#include <iostream>
#include "Matrix.cpp"

using namespace std;

void wrapper()
{
    Vector<float> v1(5.0f, 7.0f, 10.0f);
    Vector<float> v2(6.0f, 8.0f, 15.0f);

    cout << "v1: ";
    v1.Print();

    std::cout << "v2: ";
    v2.Print();

    // Vector addition
    Vector<float> vAdd = v1 + v2;
    std::cout << "v1 + v2: ";
    vAdd.Print();

    // Vector subtraction
    Vector<float> vSub = v1 - v2;
    cout << "v1 - v2: ";
    vSub.Print();

    // Scalar multiplication
    Vector<float> vScaled = v1 * 2.0;
    cout << "v1 * 2: ";
    vScaled.Print();

    // Dot product
    double dotProd = v1.Dot(v2);
    cout << "v1 . v2: " << dotProd << endl;

    // Cross product
    Vector<float> crossProd = v1.Cross(v2);
    cout << "v1 x v2: ";
    crossProd.Print();

    // Normalization
    Vector<float> vNormal = v1.Normalize();
    cout << "Normalized v1: ";
    vNormal.Print();

    cout << endl;

    Matrix<float> m1(3, 3);
    m1(0, 0) = 1.0f; m1(0, 1) = 2.0f; m1(0, 2) = 3.0f;
    m1(1, 0) = 9.0f; m1(1, 1) = -2.0f; m1(1, 2) = 5.0f;
    m1(2, 0) = 7.0f; m1(2, 1) = 8.0f; m1(2, 2) = 9.0f;

    Matrix<float> m2(3, 3);
    m2(0, 0) = 10.0f; m2(0, 1) = 11.0f; m2(0, 2) = 12.0f;
    m2(1, 0) = 13.0f; m2(1, 1) = 14.0f; m2(1, 2) = 15.0f;
    m2(2, 0) = 16.0f; m2(2, 1) = 17.0f; m2(2, 2) = 18.0f;

    cout << "m1: ";
    m1.Print();

    std::cout << "m2: ";
    m2.Print();

    // Matrix addition
    Matrix<float> mAdd = m1 + m2;
    std::cout << "m1 + m2: ";
    mAdd.Print();

    // Matrix subtraction
    Matrix<float> mSub = m1 - m2;
    cout << "m1 - m2: ";
    mSub.Print();

    // Matrix scalar multiplication
    Matrix<float> mScaled = m1 * 2;
    cout << "m1 * 2: ";
    mScaled.Print();

    // Matrix-vector multiplication
    Matrix<float> mVec = m1 * v1;
    cout << "m1 * v1: ";
    mVec.Print();

    // Matrix transpose
    Matrix<float> m1Transpose = m1.Transpose();
    cout << "m1 transposed: ";
    m1Transpose.Print();

    // Matrix inverse
    Matrix<float> mInverse = m1.Inverse();
    cout << "m1 inverse: ";
    mInverse.Print();

    // Determiniants
    cout << "m1 determinant: " << m1.Determinant() << endl;
    cout << "m2 determinant: " << m2.Determinant() << endl;
}

int main()
{
    wrapper();

    if (_CrtDumpMemoryLeaks())
    {
        cout << "Mem leaks!";
    }
}
