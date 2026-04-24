#ifndef CDIEM_H
#define CDIEM_H


class cDiem{
private:
    float x, y;

public:
    void Nhap();
    void Xuat();
    void TinhTien(float dx, float dy);
    float KhoangCach(cDiem a);
    void Quay(cDiem M, float goc);
    void PhongTo(cDiem tam, float k);
    void ThuNho(cDiem tam, float k);
};

#endif // CDIEM_H
