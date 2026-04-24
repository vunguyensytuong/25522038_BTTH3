#ifndef CTAMGIAC_H
#define CTAMGIAC_H
#include "cDiem.h"

class cTamGiac
{
private:
    cDiem A, B, C;

public:
    void Nhap();
    void Xuat();
    bool KiemTraTamGiac();
    void KiemTraLoaiTamGiac();
    float ChuVi();
    float DienTich();
    cTamGiac TinhTien(float dx, float dy);
    cTamGiac Quay(cDiem M, float goc);
    cTamGiac PhongTo(cDiem tam, float k);
    cTamGiac ThuNho(cDiem tam, float k);
};

#endif // CTAMGIAC_H
