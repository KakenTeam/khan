#include "Polynomial.h"
#include <iostream>

using namespace std;

int main()
{
    Polynomial p1, p2, p3;
    p1.Nhap();
    p1.Xuat();
    p2.Nhap();
    p3 = p1 + p2;
    p3.Xuat();
    return 0;
}
