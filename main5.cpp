#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main() {
    cDaThuc f1, f2, fSum, fDiff;
    float x;

    cout << "Nhap da thuc f1:\n";
    f1.Nhap();

    cout << "\nNhap da thuc f2:\n";
    f2.Nhap();

    cout << "\n";
    cout << "Da thuc f1: "; f1.Xuat();
    cout << "Da thuc f2: "; f2.Xuat();

    fSum = f1.CongDaThuc(f2);
    fDiff = f1.TruDaThuc(f2);

    cout << "\nTong f1 + f2: "; fSum.Xuat();
    cout << "Hieu f1 - f2: "; fDiff.Xuat();

    cout << "\nNhap gia tri x de tinh f1(x): ";
    cin >> x;
    cout << "Gia tri f1(" << x << ") = " << f1.GiaTriDaThucKhiBietX(x);

    return 0;
}
