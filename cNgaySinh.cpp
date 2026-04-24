#include "cNgaySinh.h"

cNgaySinh::cNgaySinh() {
    ngay = 1; thang = 1; nam = 2000;
}

cNgaySinh::cNgaySinh(int d, int m, int y) {
    ngay = d; thang = m; nam = y;
}

void cNgaySinh::nhap() {
    // Kiem tra gia tri ngay thang nam nhap vao
    bool hopLe;
    do {
        hopLe = true;
        cout << "Nhap ngay thang nam (cach nhau bang khoang trang): ";
        cin >> ngay >> thang >> nam;

        // Kiem tra co ban: thang tu 1-12, ngay tu 1-31, nam > 1900
        if(thang < 1 || thang > 12 || ngay < 1 || ngay > 31 || nam <= 1900) {
            cout << "[Loi] Ngay sinh khong hop le. Vui long nhap lai!\n";
            hopLe = false;
        }
    } while (!hopLe);
}

void cNgaySinh::xuat() const {
    cout << ngay << "/" << thang << "/" << nam;
}

int cNgaySinh::getNam() const {
    return nam;
}
