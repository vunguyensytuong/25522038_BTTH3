#include "cQuanLyNhanVien.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void cQuanLyNhanVien::nhapDanhSach() {
    int n;
    do {
        cout << "Nhap so luong nhan vien: ";
        cin >> n;
        if (n <= 0) cout << "[Loi] So luong phai lon hon 0!\n";
    } while (n <= 0);

    ds.resize(n);
    for(int i = 0; i < n; i++) {
        cout << "\n--- Nhap nhan vien thu " << i + 1 << " ---\n";
        ds[i].nhap();
    }
}

void cQuanLyNhanVien::xuatDanhSach() const {
    cout << "\n================ DANH SACH =================\n";
    for(const auto& nv : ds) {
        nv.xuat();
    }
}

void cQuanLyNhanVien::timLuongThapNhat() const {
    if(ds.empty()) return;
    double minLuong = ds[0].tinhLuong();
    for(const auto& nv : ds) {
        if(nv.tinhLuong() < minLuong) {
            minLuong = nv.tinhLuong();
        }
    }
    cout << "\n[*] Nhan vien co luong thap nhat (" << fixed << setprecision(0) << minLuong << "):\n";
    for(const auto& nv : ds) {
        if(nv.tinhLuong() == minLuong) nv.xuat();
    }
}

void cQuanLyNhanVien::tinhTongLuong() const {
    double tong = 0;
    for(const auto& nv : ds) {
        tong += nv.tinhLuong();
    }
    cout << "\n[*] Tong luong phai tra: " << fixed << setprecision(0) << tong << endl;
}

void cQuanLyNhanVien::timTuoiCaoNhat() const {
    if(ds.empty()) return;
    int minNam = ds[0].getNamSinh();
    for(const auto& nv : ds) {
        if(nv.getNamSinh() < minNam) {
            minNam = nv.getNamSinh();
        }
    }
    cout << "\n[*] Nhan vien co tuoi cao nhat (Sinh nam " << minNam << "):\n";
    for(const auto& nv : ds) {
        if(nv.getNamSinh() == minNam) nv.xuat();
    }
}

void cQuanLyNhanVien::sapXepTangDanTheoLuong() {
    sort(ds.begin(), ds.end(), [](const cNhanVienSX& a, const cNhanVienSX& b) {
        return a.tinhLuong() < b.tinhLuong();
    });
    cout << "\n[*] Da sap xep danh sach!\n";
}
