#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <string>
#include "cNgaySinh.h"
using namespace std;

class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    cNgaySinh ngaySinh;
    int soSanPham;
    double donGia;

public:
    cNhanVienSX();
    void nhap();
    void xuat() const;
    double tinhLuong() const;
    int getNamSinh() const;
};

#endif
