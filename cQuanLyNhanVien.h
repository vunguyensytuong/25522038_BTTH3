#ifndef CQUANLYNHANVIEN_H
#define CQUANLYNHANVIEN_H

#include <vector>
#include "cNhanVienSX.h"

class cQuanLyNhanVien {
private:
    vector<cNhanVienSX> ds; // Danh sach nhan vien
public:
    void nhapDanhSach();
    void xuatDanhSach() const;
    void timLuongThapNhat() const;
    void tinhTongLuong() const;
    void timTuoiCaoNhat() const;
    void sapXepTangDanTheoLuong();
};

#endif
