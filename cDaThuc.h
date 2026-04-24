#ifndef CDATHUC_H
#define CDATHUC_H

class cDaThuc
{
private:
    int n;
    double *p;
public:
    cDaThuc();
    ~cDaThuc();
    cDaThuc(const cDaThuc& other);
    cDaThuc& operator=(const cDaThuc& other);
    void KhoiTaoDaThuc();
    void Nhap();
    void Xuat();
    float GiaTriDaThucKhiBietX(float X);
    cDaThuc CongDaThuc(cDaThuc gx);
    cDaThuc TruDaThuc(cDaThuc gx);
};

#endif // CDATHUC_H
