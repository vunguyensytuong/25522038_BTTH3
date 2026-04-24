#ifndef CARRAY_
#define CARRAY_

class cArray {
private:
    int n;
    int *p;
public:
    cArray();
    cArray(int, int*);
    cArray(cArray&);
    ~cArray();

    void Nhap();
    void PhatSinhNgauNhien(int size, int minVal, int maxVal);
    void Xuat();
    int SoLanXXuatHien(int x);
    bool TangDan();
    int PhanTuLeNhoNhat();
    int SoNguyenToLonNhat();

    // Cac ham ho tro sap xep
    void MergeSortHelper(int left, int right);
    void Merge(int left, int mid, int right);
    void QuickSortHelper(int low, int high);
    int Partition(int low, int high);
    void Heapify(int N, int i);

    // 7 thuat toan sap xep
    void BubbleSort();
    void InsertionSort();
    void SelectionSort();
    void MergeSort();
    void QuickSort();
    void HeapSort();
    void CountingSort();
};

#endif
