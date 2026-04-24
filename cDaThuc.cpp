#include <iostream>
#include "cDaThuc.h"
#include <cmath>
#include <algorithm>

using namespace std;

cDaThuc::cDaThuc() {
    n = 0;
    p = nullptr;
}

cDaThuc::~cDaThuc() {
    if (p != nullptr) {
        delete[] p;
        p = nullptr;
    }
}

cDaThuc::cDaThuc(const cDaThuc& other) {
    n = other.n;
    if (other.p != nullptr) {
        p = new double[n + 1];
        for (int i = 0; i <= n; i++) {
            p[i] = other.p[i];
        }
    } else {
        p = nullptr;
    }
}

cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) {
        if (p != nullptr) delete[] p;
        n = other.n;
        if (other.p != nullptr) {
            p = new double[n + 1];
            for (int i = 0; i <= n; i++) {
                p[i] = other.p[i];
            }
        } else {
            p = nullptr;
        }
    }
    return *this;
}

void cDaThuc::KhoiTaoDaThuc() {
    if (p != nullptr) delete[] p;
    p = new double[n + 1];
    for (int i = 0; i <= n; i++) p[i] = 0;
}

void cDaThuc::Nhap() {
    if (p != nullptr) delete[] p;
    cout << "Nhap bac cua da thuc: ";
    cin >> n;
    p = new double[n + 1];

    for (int i = n; i >= 0; i--) {
        cout << "Nhap he so bac x^" << i << ": ";
        cin >> p[i];
    }
}

void cDaThuc::Xuat() {
    bool first = true;
    for (int i = n; i >= 0; i--) {
        if (p[i] == 0 && i != 0) continue;

        if (!first && p[i] > 0) cout << " + ";
        else if (p[i] < 0) cout << " - ";
        else if (!first && p[i] == 0 && i == 0) continue;

        if (i == 0) cout << abs(p[i]);
        else if (i == 1) cout << abs(p[i]) << "x";
        else cout << abs(p[i]) << "x^" << i;

        first = false;
    }
    if (first) cout << "0";
    cout << endl;
}

float cDaThuc::GiaTriDaThucKhiBietX(float X) {
    float KetQua = 0;
    for (int i = 0; i <= n; i++) {
        KetQua += p[i] * pow(X, i);
    }
    return KetQua;
}

cDaThuc cDaThuc::CongDaThuc(cDaThuc gx) {
    cDaThuc hx;
    hx.n = max(this->n, gx.n);
    hx.p = new double[hx.n + 1];

    for (int i = 0; i <= hx.n; i++) {
        double heSoA = (i <= this->n) ? this->p[i] : 0;
        double heSoB = (i <= gx.n) ? gx.p[i] : 0;
        hx.p[i] = heSoA + heSoB;
    }
    return hx;
}

cDaThuc cDaThuc::TruDaThuc(cDaThuc gx) {
    cDaThuc hx;
    hx.n = max(this->n, gx.n);
    hx.p = new double[hx.n + 1];

    for (int i = 0; i <= hx.n; i++) {
        double heSoA = (i <= this->n) ? this->p[i] : 0;
        double heSoB = (i <= gx.n) ? gx.p[i] : 0;
        hx.p[i] = heSoA - heSoB;
    }
    return hx;
}
