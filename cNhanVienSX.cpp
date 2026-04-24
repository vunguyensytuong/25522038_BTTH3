#include "cNhanVienSX.h"
#include <iostream>
#include <iomanip>

cNhanVienSX::cNhanVienSX() {
    maNV = ""; hoTen = ""; soSanPham = 0; donGia = 0.0;
}

void cNhanVienSX::nhap() {
    cin.ignore();
    cout << "Nhap ma nhan vien: "; getline(cin, maNV);
    cout << "Nhap ho ten: "; getline(cin, hoTen);

    ngaySinh.nhap();

    // Kiem tra so san pham phai >= 0
    do {
        cout << "Nhap so san pham: "; cin >> soSanPham;
        if(soSanPham < 0) cout << "[Loi] So san pham khong duoc am!\n";
    } while (soSanPham < 0);

    // Kiem tra don gia phai >= 0
    do {
        cout << "Nhap don gia: "; cin >> donGia;
        if(donGia < 0) cout << "[Loi] Don gia khong duoc am!\n";
    } while (donGia < 0);
}

double cNhanVienSX::tinhLuong() const {
    return soSanPham * donGia;
}

int cNhanVienSX::getNamSinh() const {
    return ngaySinh.getNam();
}

void cNhanVienSX::xuat() const {
    cout << left << setw(10) << maNV << "| " << setw(20) << hoTen << "| ";
    ngaySinh.xuat();
    cout << " | SP: " << setw(5) << soSanPham
         << " | Luong: " << fixed << setprecision(0) << tinhLuong() << endl;
}
