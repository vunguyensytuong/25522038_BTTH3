#include <iostream>
#include <cmath>
#include "cDaGiac.h"
using namespace std;

cDaGiac::cDaGiac() {
    n = 0;
    dsDiem = nullptr;
}

cDaGiac::cDaGiac(const cDaGiac& other) {
    n = other.n;
    if (n > 0) {
        dsDiem = new cDiem[n];
        for (int i = 0; i < n; i++) {
            dsDiem[i] = other.dsDiem[i];
        }
    } else {
        dsDiem = nullptr;
    }
}

cDaGiac& cDaGiac::operator=(const cDaGiac& other) {
    if (this != &other) {
        delete[] dsDiem;
        n = other.n;
        if (n > 0) {
            dsDiem = new cDiem[n];
            for (int i = 0; i < n; i++) {
                dsDiem[i] = other.dsDiem[i];
            }
        } else {
            dsDiem = nullptr;
        }
    }
    return *this;
}

cDaGiac::~cDaGiac() {
    delete[] dsDiem;
}

// Kiem tra da giac co hop le (ton tai) hay khong
bool cDaGiac::KiemTraTonTai() {
    // Da giac phai co it nhat 3 dinh
    if (n < 3) return false;

    // Neu tat ca cac dinh nam tren 1 duong thang (hoac trung nhau)
    // thi dien tich se bang 0: Khong the tao thanh da giac
    if (DienTich() <= 0.0001) {
        return false;
    }

    return true; // Hop le
}

//Ham nhap toa do
void cDaGiac::Nhap() {
    while (true) {
        cout << "Nhap so dinh cua da giac (n >= 3): ";
        cin >> n;
        // Kiem tra loi nhap ky tu hoac so dinh < 3
        if (cin.fail() || n < 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Loi! So dinh phai la so nguyen >= 3. Vui long nhap lai.\n";
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }

    dsDiem = new cDiem[n]; // Cap phat mang dsDiem dua tren so dinh n
    while (true){
        for (int i = 0; i < n; i++) {
            cout << "- Nhap toa do dinh thu " << i + 1 << ":\n";
            dsDiem[i].Nhap(); // Goi ham Nhap cua lop cDiem
        }
        if(KiemTraTonTai()) break;
        cout<<"Vui long nhap 1 da giac ton tai.\n";
    }
}

//Ham xuat toa do
void cDaGiac::Xuat() {
    for (int i = 0; i < n; i++) {
        dsDiem[i].Xuat();
        if (i < n - 1) cout << " - ";
    }
    cout << "\n";
}

//Kiem tra Da giac Loi hay Lom
void cDaGiac::KiemTraLoaiDaGiac() {
    if (n < 3) return;
    bool hasPos = false, hasNeg = false;

    // Dung tich co huong (Cross Product) cua 2 vector lien tiep
    // De kiem tra xem cac dinh co "re" cung mot huong hay khong
    for (int i = 0; i < n; i++) {
        int prev = (i == 0) ? n - 1 : i - 1;
        int next = (i + 1) % n;

        // Tinh toa do vector 1 va vector 2
        float dx1 = dsDiem[i].getX() - dsDiem[prev].getX();
        float dy1 = dsDiem[i].getY() - dsDiem[prev].getY();
        float dx2 = dsDiem[next].getX() - dsDiem[i].getX();
        float dy2 = dsDiem[next].getY() - dsDiem[i].getY();

        //tich co huong
        float crossProduct = dx1 * dy2 - dy1 * dx2;

        if (crossProduct > 0) hasPos = true;
        if (crossProduct < 0) hasNeg = true;
    }

    // Neu vua co re trai vua co re phai -> hinh bi lom vao trong
    if (hasPos && hasNeg) cout << "Day la da giac lom.\n";
    else cout << "Day la da giac loi.\n";
}

//Tinh chu vi
float cDaGiac::ChuVi() {
    if (n < 3) return 0;
    float cv = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n; // Noi dinh cuoi cung voi dinh dau tien
        cv += dsDiem[i].KhoangCach(dsDiem[next]);
    }
    return cv;
}

//Tinh dien tich
float cDaGiac::DienTich() {
    if (n < 3) return 0;
    float area = 0;

    // Ap dung cong thuc Shoelace (Cong thuc day giay) danh cho da giac bat ky
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        area += (dsDiem[i].getX() * dsDiem[next].getY()) - (dsDiem[next].getX() * dsDiem[i].getY());
    }
    return abs(area) / 2.0; // Tri tuyet doi va chia 2
}


//tinh tien
cDaGiac cDaGiac::TinhTien(float dx, float dy) {
    cDaGiac kq = *this; // Tao ra mot ban sao ten la kq
    // Tinh tien tung dinh mot cua ban sao
    for (int i = 0; i < n; i++) kq.dsDiem[i].TinhTien(dx, dy);
    return kq; // Tra ve ban sao
}

//Phep quay quanh 1 tam
cDaGiac cDaGiac::Quay(cDiem tam, float goc) {
    cDaGiac kq = *this;
    for (int i = 0; i < n; i++) kq.dsDiem[i].Quay(tam, goc);
    return kq;
}

//Phep phong to (Vi tu ty so k)
cDaGiac cDaGiac::PhongTo(cDiem tam, float k) {
    cDaGiac kq = *this;
    for (int i = 0; i < n; i++) kq.dsDiem[i].PhongTo(tam, k);
    return kq;
}

//Phep thu nho (Vi tu ty so 1/k)
cDaGiac cDaGiac::ThuNho(cDiem tam, float k) {
    cDaGiac kq = *this;
    for (int i = 0; i < n; i++) kq.dsDiem[i].ThuNho(tam, k);
    return kq;
}
