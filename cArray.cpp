#include <iostream>
#include "cArray.h"
using namespace std;

cArray::cArray()
{
    n=0;
    p=nullptr;
}
cArray::cArray(int size,int* a){
    n=size;
    p= new int [n];
    for(int i=0;i<n;i++){
        p[i]=a[i];
    }
}
cArray::cArray(cArray& other){
    n=other.n;
    p=new int [n];
    for(int i=0;i<n;i++){
        p[i]=other.p[i];
    }
}
cArray::~cArray()
{
    delete[] p;
}
// Ham phat sinh so ngau nhien
void cArray::PhatSinhNgauNhien(int size, int minVal, int maxVal) {
    if (p != nullptr) delete[] p; // Xoa mang cu neu da ton tai
    n = size;
    p = new int[n];
    srand(time(NULL)); // Khoi tao hat giong ngau nhien theo thoi gian
    for (int i = 0; i < n; i++) {
        p[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

// Ham nhap mang tu ban phim
void cArray::Nhap() {
    if (p != nullptr) delete[] p;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap p[" << i << "]: ";
        cin >> p[i];
    }
}

//ham xuat 1 mang
void cArray::Xuat(){
    for (int i=0;i<n;i++){
        cout<<p[i]<<' ';
    }
    cout<<'\n';
}

int cArray::SoLanXXuatHien(int x){
    int KetQua=0;
    for (int i=0;i<n;i++){
        if (p[i]==x) KetQua++;
    }
    return KetQua;
}

bool cArray::TangDan(){
    for (int i=1;i<n;i++){
        if (p[i-1]>p[i]) return false;
    }
    return true;
}

int cArray::PhanTuLeNhoNhat() {
    int res = 0; // Dung 0 de lam dau hieu "khong tim thay"
    bool daTimThay = false;

    for (int i = 0; i < n; i++) {
        // Kiem tra so le
        if (p[i] % 2 != 0) {
            // Neu day la so le DAU TIEN tim duoc
            if (daTimThay == false) {
                res = p[i]; // Lay no lam chuan (Min tam thoi)
                daTimThay = true;
            }
            // Tu so le thu 2 tro di, tien hanh so sanh de tim Min
            else if (p[i] < res) {
                res = p[i];
            }
        }
    }
    return res;
}

//ham kiem tra so nguyen to
bool KiemTraSoNguyenTo(int x){
    if (x < 2) return false; // Nho hon 2 khong phai so nguyen to
    for (int i = 2; i * i <= x; i++){ // Phai la i*i <= x hoac i <= sqrt(x)
        if (x % i == 0) return false;
    }
    return true;
}

int cArray::SoNguyenToLonNhat(){
    int KetQua=-1;
    for (int i=0;i<n;i++){
        if (KiemTraSoNguyenTo(p[i])){
            if (p[i]>KetQua) KetQua=p[i];
        }
    }
    return KetQua;
}

//bubble sort
void cArray::BubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        // Day phan tu lon nhat ve cuoi mang
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                swap(p[j], p[j + 1]);
                swapped = true;
            }
        }
        cout << "Buoc " << i + 1 << ": ";
        Xuat();
        // Neu khong co doi cho nao xay ra: Mang da sap xep dung
        if (!swapped) break;
    }
}

//Insertion Sort
void cArray::InsertionSort() {
    for (int i = 1; i < n; i++) {
        int key = p[i];
        int j = i - 1;
        // Doi cac phan tu lon hon key sang phai 1 vi tri
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        // Chen key vao vi tri dung
        p[j + 1] = key;
        cout << "Buoc " << i << " (Chen " << key << "): ";
        Xuat();
    }
}

//Selection Sort
void cArray::SelectionSort() {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // Tim phan tu nho nhat trong doan chua sap xep
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[min_idx]) {
                min_idx = j;
            }
        }
        // Doi cho voi phan tu dau tien cua doan
        swap(p[min_idx], p[i]);
        cout << "Buoc " << i + 1 << ": ";
        Xuat();
    }
}

// Merge Sort
void cArray::Merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Tao mang tam de luu 2 nua
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = p[left + i];
    for (int j = 0; j < n2; j++) R[j] = p[mid + 1 + j];

    // Tron 2 mang tam tro lai mang chinh p
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { p[k] = L[i]; i++; }
        else { p[k] = R[j]; j++; }
        k++;
    }
    // Dua cac phan tu con lai vao mang (neu co)
    while (i < n1) { p[k] = L[i]; i++; k++; }
    while (j < n2) { p[k] = R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

void cArray::MergeSortHelper(int left, int right) {
    if (left >= right) return; // Dieu kien dung de quy
    int mid = left + (right - left) / 2;
    // Chia doi va goi de quy
    MergeSortHelper(left, mid);
    MergeSortHelper(mid + 1, right);
    // Tron lai
    Merge(left, mid, right);

    cout << "Tron tu " << left << " den " << right << ": ";
    Xuat(); // In mang sau moi lan tron
}

void cArray::MergeSort() {
    MergeSortHelper(0, n - 1);
}

//Quick Sort
int cArray::Partition(int low, int high) {
    int pivot = p[high]; // Chon phan tu cuoi cung lam chot
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        // Neu phan tu nho hon pivot, doi no sang ben trai
        if (p[j] < pivot) {
            i++;
            swap(p[i], p[j]);
        }
    }
    swap(p[i + 1], p[high]);
    return (i + 1); // Tra ve vi tri cua pivot
}

void cArray::QuickSortHelper(int low, int high) {
    if (low < high) {
        int pi = Partition(low, high);
        cout << "Chot (pivot) la " << p[pi] << " tai vi tri " << pi << ": ";
        Xuat();
        // De quy 2 nua trai va phai
        QuickSortHelper(low, pi - 1);
        QuickSortHelper(pi + 1, high);
    }
}

void cArray::QuickSort() {
    QuickSortHelper(0, n - 1);
}

//Heap Sort
void cArray::Heapify(int N, int i) {
    int largest = i; // Khoi tao largest la root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Kiem tra node con trai va phai
    if (left < N && p[left] > p[largest]) largest = left;
    if (right < N && p[right] > p[largest]) largest = right;

    // Neu largest khong phai la root, swap va tiep tuc vun dong
    if (largest != i) {
        swap(p[i], p[largest]);
        Heapify(N, largest);
    }
}

void cArray::HeapSort() {
    // Xay dung Max Heap tu mang ban dau
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify(n, i);
    }
    cout << "Max Heap ban dau: ";
    Xuat();

    // Rut tung phan tu ra khoi heap
    for (int i = n - 1; i > 0; i--) {
        // Chuyen root (lon nhat) ve cuoi mang
        swap(p[0], p[i]);
        cout << "Dua " << p[i] << " ve cuoi mang: ";
        Xuat();
        // Vun dong lai phan con lai
        Heapify(i, 0);
    }
}

// Counting Sort (Sap xep dem)
void cArray::CountingSort() {
    cout << "\n--- Counting Sort ---\n";
    if (n <= 1) return;

    // Tim max va min de ho tro mang co so am
    int max_val = p[0], min_val = p[0];
    for (int i = 1; i < n; i++) {
        if (p[i] > max_val) max_val = p[i];
        if (p[i] < min_val) min_val = p[i];
    }

    int range = max_val - min_val + 1;
    int* count = new int[range]{0}; // Khoi tao mang dem toan so 0
    int* output = new int[n];       // Mang luu ket qua tam

    // Dem so lan xuat hien
    for (int i = 0; i < n; i++) count[p[i] - min_val]++;

    // Cong don (prefix sum) de xac dinh vi tri
    for (int i = 1; i < range; i++) count[i] += count[i - 1];

    // Xep vao output (duyet tu cuoi de dam bao tinh on dinh - stable sort)
    for (int i = n - 1; i >= 0; i--) {
        output[count[p[i] - min_val] - 1] = p[i];
        count[p[i] - min_val]--;
    }

    // Chep lai vao mang p
    for (int i = 0; i < n; i++) p[i] = output[i];

    cout << "Mang sau khi dem va xep lai: ";
    Xuat();

    delete[] count;
    delete[] output;
}
