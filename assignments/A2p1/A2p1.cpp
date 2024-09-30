// A2p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Function1();
void Function1a();
void Function2();
void Function3();
void Function4();

int main()
{
    Function1();
    cout << endl;

    Function1a();
    cout << endl;

    Function2();
    cout << endl;

    Function3();
    cout << endl;

    Function4();
    cout << endl;
}

void Function1()
{
    // Function 1
    int a, b, c, d;
    a = 3;
    b = a++ + ++a;
    c = a++ + ++b;
    std::cout << a << b << c;
}

void Function1a()
{
    /* had a typo here! OK to skip this one or just call it “Function 1a */
    int a, b, c;
    a = 5;
    b = 7;
    c = a + 4 < b;
    cout << a << b << c;
}

void Function2()
{
    // Function 2
    int a, b, c, d;
    a = 5;
    b = 2;
    c = a < b;
    cout << c;
    c = a < b + 4;
    cout << c;
    d = a < b++;
    cout << a << b << c << d;
    c = a + b++ + c++;
    d = ++a + b++ + ++c;
    cout << a << b << c << d;
}

void Function3()
{
    // Function 3
    int a, b, * p, * q, * r;
    a = 3;
    b = 6;
    p = &b;
    q = &a;
    *p = *q + 3;
    r = p;
    p = q;
    q = r;
    cout << a << b << *p << *q << *r;
}

void Function4()
{
    // Function 4
    int a, b = 7;
    int* p, * q, ** r, *** s;
    s = &r;
    r = &q;
    p = &a;
    r = &p;
    a = 5;
    q = &b;
    **r = *p - 6; // fixed!
    cout << a << b << *p << *q << **r << ***s;
}
