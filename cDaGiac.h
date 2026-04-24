#ifndef CDAGIAC_H
#define CDAGIAC_H
#include "cDiem.h"

class cDaGiac
{
private:
    int n;
    cDiem *dsDiem;
public:
    cDaGiac();
    cDaGiac(const cDaGiac& other);
    cDaGiac& operator=(const cDaGiac& other);
    ~cDaGiac();

    void Nhap();
    void Xuat();
    bool KiemTraTonTai();
    void KiemTraLoaiDaGiac();
    float ChuVi();
    float DienTich();
    cDaGiac TinhTien(float dx, float dy);
    cDaGiac Quay(cDiem tam, float goc);
    cDaGiac PhongTo(cDiem tam, float k);
    cDaGiac ThuNho(cDiem tam, float k);
};

#endif // CDAGIAC_H
