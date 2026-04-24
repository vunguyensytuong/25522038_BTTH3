#include <iostream>
#include <string>
#include "cDaGiac.h"
#include "cDiem.h"
#define Pi 3.14159265358979323846
using namespace std;

bool KiemTraFloat(string s);

int main()
{
    cDaGiac DG;
    DG.Nhap();

    cout << "\nDa giac vua nhap:\n";
    DG.Xuat();

    DG.KiemTraLoaiDaGiac();

    float ChuViDG = DG.ChuVi();
    cout << "Chu vi da giac: " << ChuViDG << "\n";
    float DienTichDG = DG.DienTich();
    cout << "Dien tich da giac: " << DienTichDG << "\n";
    cout<<"\n";

    string Tdx, Tdy;
    cout << "\nNhap vector tinh tien dx: ";
    cin >> Tdx;
    while (!KiemTraFloat(Tdx)) { cout << "Vui long nhap lai dx: "; cin >> Tdx; }
    float dx = stof(Tdx);

    cout << "Nhap vector tinh tien dy: ";
    cin >> Tdy;
    while (!KiemTraFloat(Tdy)) { cout << "Vui long nhap lai dy: "; cin >> Tdy; }
    float dy = stof(Tdy);

    cDaGiac DGTinhTien = DG.TinhTien(dx, dy);
    cout << "Da giac sau khi tinh tien:\n";
    DGTinhTien.Xuat();

    cDiem M;
    cout << "\nNhap tam quay M:\n";
    M.Nhap();
    int chon;
    while (true){
        cout << "Chon goc quay:\n[1] de chon Do\n[2] de chon Radian\n";
        cin >> chon;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Loi! Vui long chi nhap so 1 hoac 2.\n\n";
            continue;
        }
        if (chon == 1 || chon == 2) break;
        cout << "Nhap sai. Vui long nhap lai.\n\n";
    }

    string Tgoc;
    float goc;
    if (chon == 1){
        cout << "Nhap goc quay (theo Do): ";
        cin >> Tgoc;
        while (!KiemTraFloat(Tgoc)) { cout << "Vui long nhap lai goc: "; cin >> Tgoc; }
        goc = stof(Tgoc) * (Pi / 180.0);
    }
    else {
        cout << "Nhap goc quay (theo Radian): ";
        cin >> Tgoc;
        while (!KiemTraFloat(Tgoc)) { cout << "Vui long nhap lai goc: "; cin >> Tgoc; }
        goc = stof(Tgoc);
    }

    cDaGiac DGQuay = DG.Quay(M, goc);
    cout << "Da giac sau khi quay:\n";
    DGQuay.Xuat();

    cDiem TamThuPhong;
    cout << "\nNhap tam thu phong (vi tu):\n";
    TamThuPhong.Nhap();

    string Tk_phongto;
    cout << "Nhap he so phong to: ";
    cin >> Tk_phongto;
    while (!KiemTraFloat(Tk_phongto)) { cout << "Vui long nhap lai he so: "; cin >> Tk_phongto; }
    float k_phongto = stof(Tk_phongto);

    cDaGiac DGPhongTo = DG.PhongTo(TamThuPhong, k_phongto);
    cout << "Da giac sau khi phong to:\n";
    DGPhongTo.Xuat();

    string Tk_thunho;
    cout << "\nNhap he so thu nho: ";
    cin >> Tk_thunho;
    while (!KiemTraFloat(Tk_thunho)) { cout << "Vui long nhap lai he so: "; cin >> Tk_thunho; }
    float k_thunho = stof(Tk_thunho);

    cDaGiac DGThuNho = DG.ThuNho(TamThuPhong, k_thunho);
    cout << "Da giac sau khi thu nho:\n";
    DGThuNho.Xuat();

    return 0;
}
