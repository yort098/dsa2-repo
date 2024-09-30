#include "Vector.cpp"
#include <iostream>

template <class T>
class Matrix
{
private:
	T** data;
	int rows, cols;
public:
	Matrix(size_t rows, size_t cols);
	~Matrix();

	// Access elements (non-const version)
	T& operator()(size_t r, size_t c) {
		if (r >= rows || c >= cols) throw std::out_of_range("Index out of bounds");
		return data[r][c];
	}

	const T& operator()(size_t r, size_t c) const 
	{
		return data[r][c];
	}

	Matrix<T> operator +(const Matrix<T>& other);
	Matrix<T> operator -(const Matrix<T>& other);
	Matrix<T> operator *(const Vector<T>& vec);
	Matrix<T> operator *(T scalar);
	
	T Determinant();

	Matrix<T> Transpose();
	Matrix<T> Inverse();

	Matrix<T> getSubmatrix(size_t excludeRow, size_t excludeCol);

	void Print();


};

template<class T>
Matrix<T>::Matrix(size_t rows, size_t cols)
{
	this->rows = rows;
	this->cols = cols;

	data = new T*[rows];
	for (int i = 0; i < rows; ++i)
	{
		data[i] = new T[cols]();
	}
}

template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] data[i];
	}

	delete[] data;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other)
{
	if (rows != other.rows || cols != other.cols)
	{
		throw std::invalid_argument("Matrix dimensions must match for addition");
	}
		

	Matrix<T> result(rows, cols);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			result(i, j) = data[i][j] + other(i, j);
		}
	}
		
	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other)
{
	if (rows != other.rows || cols != other.cols)
	{
		throw std::invalid_argument("Matrix dimensions must match for subtraction");
	}


	Matrix<T> result(rows, cols);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			result(i, j) = data[i][j] - other(i, j);
		}
	}

	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Vector<T>& vec)
{
	if (cols != 3)
	{
		throw std::invalid_argument("Matrix columns must match vector size");
	}
		
	Matrix<T> result(rows, 1);
	for (int i = 0; i < rows; ++i)
	{
		result(i, 0) = 0;
		for (int j = 0; j < cols; ++j)
		{
			result(i, 0) += data[i][j] * vec[j];
		}
	}
		
			
	return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(T scalar)
{
	Matrix<T> result(rows, cols);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			result(i, j) = data[i][j] * scalar;
		}
	}
		
	return result;
}

template<class T>
T Matrix<T>::Determinant()
{
	if (rows != cols) throw std::invalid_argument("Determinant only defined for square matrices");
	if (rows == 1) return data[0][0];
	if (rows == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];

	T det = 0;
	for (size_t i = 0; i < cols; ++i) {
		Matrix<T> submatrix = getSubmatrix(0, i);
		det += (i % 2 == 0 ? 1 : -1) * data[0][i] * submatrix.Determinant();
	}
	return det;
}

template<class T>
Matrix<T> Matrix<T>::Transpose()
{
	Matrix<T> result(cols, rows);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			result(j, i) = data[i][j];
		}
	}
		
	return result;
}

template<class T>
Matrix<T> Matrix<T>::Inverse()
{
	if (rows != cols) {
		throw std::invalid_argument("Matrix inversion only defined for square matrices");
	}

	// Step 1: Calculate the determinant
	T det = Determinant();
	if (det == 0) {
		throw std::runtime_error("Matrix is singular and cannot be inverted");
	}

	// Step 2: Create cofactor matrix
	Matrix<T> cofactorMatrix(rows, cols);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			// Cofactor is determinant of the submatrix, with alternating signs
			Matrix<T> submatrix = getSubmatrix(i, j);
			cofactorMatrix(i, j) = ((i + j) % 2 == 0 ? 1 : -1) * submatrix.Determinant();
		}
	}

	// Step 3: Transpose the cofactor matrix (this gives us the adjugate matrix)
	Matrix<T> adjugateMatrix = cofactorMatrix.Transpose();

	// Step 4: Divide the adjugate matrix by the determinant to get the inverse
	Matrix<T> inverseMatrix(rows, cols);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			inverseMatrix(i, j) = adjugateMatrix(i, j) / det;
		}
	}

	return inverseMatrix;
}

template<class T>
Matrix<T> Matrix<T>::getSubmatrix(size_t excludeRow, size_t excludeCol)
{
	Matrix<T> submatrix(rows - 1, cols - 1);
	size_t r = 0;
	for (size_t i = 0; i < rows; ++i) {
		if (i == excludeRow) continue;
		size_t c = 0;
		for (size_t j = 0; j < cols; ++j) {
			if (j == excludeCol) continue;
			submatrix(r, c) = data[i][j];
			++c;
		}
		++r;
	}
	return submatrix;
}

template<class T>
void Matrix<T>::Print()
{
	for (int i = 0; i < rows; ++i) 
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
