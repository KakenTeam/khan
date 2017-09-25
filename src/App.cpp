#include "App.h"
#include "Polynomial.h"
#include <iostream>
using namespace std;

App::App()
{
    //ctor
}

void App::Run()
{
    Polynomial p1, p2, p3;
    while (true) {
        cout << "\nNhap yeu cau:\n";
        cout << "1. Nhap da thuc 1: \n";
        cout << "2. Nhap da thuc 2: \n";
        cout << "3. Dao ham: \n";
        cout << "4. Cong 2 da thuc: \n";
        cout << "5. Thoat!!! \n";
        int temp;
        cin >> temp;
        switch (temp) {
        case 1:
            p1.Nhap();
            p1.Xuat();
            break;
        case 2:
            p2.Nhap();
            p2.Xuat();
            break;
        case 3:
            cout << "1. Dao ham da thuc 1! \n";
            cout << "2. Dao hamda thuc 2! \n";
            int temp2;
            cin >> (temp2);
            switch (temp2) {
                case 1:
                    p1.DaoHam();
                    p1.Xuat();
                    break;
                case 2:
                    p2.DaoHam();
                    p2.Xuat();
                    break;
            }
            break;
        case 4:
            p3 = p1 + p2;
            p3.Xuat();
            break;
        case 5:
            return;
            break;
        }
    }
}

