#ifndef CNGAYSINH_H
#define CNGAYSINH_H

#include <iostream>
using namespace std;

class cNgaySinh {
private:
    int ngay, thang, nam;
public:
    cNgaySinh();
    cNgaySinh(int d, int m, int y);
    void nhap();
    void xuat() const;
    int getNam() const;
};

#endif
