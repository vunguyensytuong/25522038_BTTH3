#include <iostream>
#include "cArray.h"
using namespace std;

int main() {
    cArray mangGoc;
    int cachNhap;

    cout << "1. Nhap mang tu ban phim\n";
    cout << "2. Phat sinh mang ngau nhien\n";
    cout << "Chon (1-2): ";
    cin >> cachNhap;

    if (cachNhap == 1) {
        mangGoc.Nhap();
    } else {
        int n, minV, maxV;
        cout << "Nhap so luong phan tu muon tao: "; cin >> n;
        cout << "Nhap khoang gia tri (vi du 1 100): "; cin >> minV >> maxV;
        mangGoc.PhatSinhNgauNhien(n, minV, maxV);
        cout << "Mang ngau nhien da duoc tao!\n";
    }

    cout << "Mang hien tai: "; mangGoc.Xuat();

    if (mangGoc.TangDan()) cout << "-> Mang dang TANG DAN\n";
    else cout << "-> Mang KHONG tang dan\n";

    int leMin = mangGoc.PhanTuLeNhoNhat();
    if (leMin == 0) { // Sua o day
        cout << "-> Khong co so le trong mang\n";
    } else {
        cout << "-> So le nho nhat: " << leMin << endl;
    }

    int sntMax = mangGoc.SoNguyenToLonNhat();
    if (sntMax == -1) cout << "-> Khong co so nguyen to\n";
    else cout << "-> So nguyen to lon nhat: " << sntMax << endl;

    int x;
    cout << "Nhap x de dem: "; cin >> x;
    cout << "-> So lan xuat hien cua " << x << ": " << mangGoc.SoLanXXuatHien(x) << endl;

    int luaChon;
    do {
        cout << "1. Bubble Sort      2. Insertion Sort   3. Selection Sort\n";
        cout << "4. Merge Sort       5. Quick Sort       6. Heap Sort\n";
        cout << "7. Counting Sort    0. Thoat\n";
        cout << "Chon thuat toan (0-7): ";
        cin >> luaChon;

        if (luaChon >= 1 && luaChon <= 7) {
            cArray mangTam(mangGoc); // Sao chep mang de khong mat du lieu goc
            switch (luaChon) {
                case 1: mangTam.BubbleSort(); break;
                case 2: mangTam.InsertionSort(); break;
                case 3: mangTam.SelectionSort(); break;
                case 4: mangTam.MergeSort(); break;
                case 5: mangTam.QuickSort(); break;
                case 6: mangTam.HeapSort(); break;
                case 7: mangTam.CountingSort(); break;
            }
            cout << "=> KET QUA CUOI CUNG: "; mangTam.Xuat();
        }
    } while (luaChon != 0);

    return 0;
}
