#include <iostream>

template <class T>
class Vector
{
private:
	T* data;
public:
	Vector(T x = 0, T y = 0, T z= 0);
	~Vector();

	 const T& operator[](size_t i) const {
        return data[i];
    }

	// Arithmetic
	Vector<T> operator+(const Vector<T>& other);
	Vector<T> operator -(const Vector<T>& other);
	Vector<T> operator *(T scalar);
	Vector<T> operator /(T scalar);

	T Magnitude();
	Vector<T> Normalize();

	T Dot(const Vector<T>& other);
	Vector<T> Cross(const Vector<T>& other);

	void Print();
};

template<class T>
Vector<T>::Vector(T x, T y, T z)
{
	data = new T[3]{x, y, z};
}

template<class T>
Vector<T>::~Vector()
{
	delete data;
}

// Vector addition
template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	return Vector<T>(data[0] + other[0], data[1] + other[1], data[2] + other[2]);
}

// Vector subtraction
template<class T>
Vector<T> Vector<T>::operator-(const Vector<T>& other)
{
	return Vector<T>(data[0] - other[0], data[1] - other[1], data[2] - other[2]);
}

// Scalar multiplication
template<class T>
Vector<T> Vector<T>::operator*(T scalar)
{
	return Vector<T>(data[0] * scalar, data[1] * scalar, data[2] * scalar);
}

template<class T>
Vector<T> Vector<T>::operator/(T scalar)
{
	if (scalar == 0)
	{
		return Vector<T>(0, 0, 0);
	}

	return Vector<T>(data[0] / scalar, data[1] / scalar, data[2] / scalar);
}

template<class T>
T Vector<T>::Magnitude()
{
	return std::sqrt(Dot(*this));;
}

template<class T>
T Vector<T>::Dot(const Vector<T>& other)
{
	return data[0] * other[0] + data[1] * other[1] + data[2] * other[2];
}

template<class T>
Vector<T> Vector<T>::Cross(const Vector<T>& other)
{
	return Vector<T>(
		data[1] * other[2] - data[2] * other[1],
		data[2] * other[0] - data[0] * other[2],
		data[0] * other[1] - data[1] * other[0]
	);
}

template<class T>
Vector<T> Vector<T>::Normalize()
{
	return *this/Magnitude();
}

template<class T>
void Vector<T>::Print()
{
	for (int i = 0; i < 3; ++i)
	{
		std::cout << data[i] << ", ";
	}
	std::cout << std::endl;
}

