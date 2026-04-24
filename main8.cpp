#include "cQuanLyNhanVien.h"

int main() {
    // Khoi tao doi tuong quan ly
    cQuanLyNhanVien ql;

    // Goi cac ham thuc thi yeu cau
    ql.nhapDanhSach();

    ql.xuatDanhSach();

    ql.timLuongThapNhat();

    ql.tinhTongLuong();

    ql.timTuoiCaoNhat();

    ql.sapXepTangDanTheoLuong();
    ql.xuatDanhSach(); // In lai sau khi sap xep

    return 0;
}
