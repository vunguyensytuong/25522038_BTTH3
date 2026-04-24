#include <iostream>
#include "cTamGiac.h"
#include "cDiem.h"
#include <cmath>
#include <algorithm> // Khai bao de su dung ham max()

using namespace std;

// Ham ho tro so sanh 2 so thuc voi do chinh xac eps
bool bangNhau(float a, float b) {
    float eps = 1e-6f;
    float nguong = max(1.0f, max(fabs(a), fabs(b)));
    float saiSo = fabs(a - b);
    return saiSo < eps * nguong;
}

// Kiem tra dieu kien tao thanh tam giac
bool cTamGiac::KiemTraTamGiac() {
    float a = B.KhoangCach(C);
    float b = A.KhoangCach(C);
    float c = A.KhoangCach(B);

    // Kiem tra xem 3 diem co thang hang hay khong
    if (bangNhau(a + b, c)) return false;
    if (bangNhau(a + c, b)) return false;
    if (bangNhau(b + c, a)) return false;

    // Kiem tra bat dang thuc tam giac
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Nhap toa do 3 dinh cua tam giac, bao loi nhap lai neu tam giac khong hop le
void cTamGiac::Nhap() {
    while (true) {
        cout << "Nhap toa do dinh A (x y):\n"; A.Nhap();
        cout << "Nhap toa do dinh B (x y):\n"; B.Nhap();
        cout << "Nhap toa do dinh C (x y):\n"; C.Nhap();

        if (KiemTraTamGiac()) break;

        cout << "Loi! Khong phai tam giac.\n";
        cout << "Vui long nhap 1 tam giac hop le.\n";
    }
}

// Xuat 3 diem tao nen tam giac
void cTamGiac::Xuat() {
    cout << "Tam giac duoc tao boi ba diem: ";
    A.Xuat(); cout << " ";
    B.Xuat(); cout << " ";
    C.Xuat();
    cout << "\n";
}

// Kiem tra loai tam giac bang cach dung ham bangNhau() thay cho "=="
void cTamGiac::KiemTraLoaiTamGiac() {
    float a = B.KhoangCach(C);
    float b = A.KhoangCach(C);
    float c = A.KhoangCach(B);

    // Kiem tra tam giac can
    if (bangNhau(a, b) || bangNhau(b, c) || bangNhau(a, c)) {
        // Kiem tra tam giac deu
        if (bangNhau(a, b) && bangNhau(a, c)) {
            cout << "\nDay la tam giac deu.\n";
            return;
        }
        // Kiem tra tam giac vuong can (Pytago)
        if (bangNhau(a*a + b*b, c*c) || bangNhau(a*a + c*c, b*b) || bangNhau(b*b + c*c, a*a)) {
            cout << "\nDay la tam giac vuong can.\n";
            return;
        }
        cout << "\nDay la tam giac can.\n"; // Da bo sung truong hop tam giac can thuong
        return;
    }

    // Kiem tra tam giac vuong bang Pytago
    if (bangNhau(a*a + b*b, c*c) || bangNhau(a*a + c*c, b*b) || bangNhau(b*b + c*c, a*a)) {
        cout << "\nDay la tam giac vuong.\n";
        return;
    }

    cout << "\nDay la tam giac thuong.\n";
    return;
}

// Tinh chu vi
float cTamGiac::ChuVi() {
    float a = B.KhoangCach(C);
    float b = A.KhoangCach(C);
    float c = A.KhoangCach(B);

    return a + b + c;
}

// Tinh dien tich bang cong thuc Heron
float cTamGiac::DienTich() {
    float a = B.KhoangCach(C);
    float b = A.KhoangCach(C);
    float c = A.KhoangCach(B);
    float p = ChuVi() / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Tinh tien tam giac
cTamGiac cTamGiac::TinhTien(float dx, float dy) {
    cTamGiac KetQua = *this; // Copy tam giac hien tai
    KetQua.A.TinhTien(dx, dy);
    KetQua.B.TinhTien(dx, dy);
    KetQua.C.TinhTien(dx, dy);
    return KetQua;
}

// Quay tam giac quanh diem M mot goc
cTamGiac cTamGiac::Quay(cDiem M, float goc) {
    cTamGiac KetQua = *this; // Copy tam giac hien tai
    KetQua.A.Quay(M, goc);
    KetQua.B.Quay(M, goc);
    KetQua.C.Quay(M, goc);
    return KetQua;
}

cTamGiac cTamGiac::PhongTo(cDiem tam, float k) {
    cTamGiac tamGiacMoi = *this;
    tamGiacMoi.A.PhongTo(tam, k);
    tamGiacMoi.B.PhongTo(tam, k);
    tamGiacMoi.C.PhongTo(tam, k);
    return tamGiacMoi;
}

cTamGiac cTamGiac::ThuNho(cDiem tam, float k) {
    cTamGiac tamGiacMoi = *this;
    tamGiacMoi.A.ThuNho(tam, k);
    tamGiacMoi.B.ThuNho(tam, k);
    tamGiacMoi.C.ThuNho(tam, k);
    return tamGiacMoi;
}
