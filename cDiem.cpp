#include <iostream>
#include "cDiem.h"
#include <string>
#include <cmath>
using namespace std;

//Kiem tra chuoi co phai so thuc khong
bool KiemTraFloat(string s){
    if (s.empty()) return false;
    //neu chuoi rong thi sai

    int SoCham=0;
    int Bdau=0;
    //kiem tra dau am o dau
    if (s[0]=='-'){
        if (s.length()==1) {
            cout<<"Loi! Chi co ki tu '-'.\nVui long nhap dung kieu so thuc.\n";
            return false;
        }
        Bdau=1;
    }

    //duyet qua tung ki tu
    for (int i=Bdau;i<s.length();i++){
        if (s[i]=='.'){
            SoCham++;
            if (SoCham>1){
                cout<<"Loi! Co qua nhieu dau '.'.\nVui long nhap dung kieu so thuc.\n";
                return false;
            }
            continue;
        }

        if (s[i]<'0' || s[i]>'9'){
            cout<<"Loi! Co cac ki tu ngoai [0;9].\nVui long nhap dung kieu so thuc.\n";
            return false;
        }
    }

    if (s=="." || s=="-."){
        cout<<"Loi! Dinh dang khong hop le.\nVui long nhap dung kieu so thuc.\n";
        return false;
    }

    return true;
}

//Nhap toa do x, y cua diem, bao loi nhap lai neu khong nhap so thuc
void cDiem::Nhap(){
    string Tx,Ty;
    cout<<"Nhap x: ";
    cin>>Tx;
    while (!KiemTraFloat(Tx)){
        cout<<"Vui long nhap lai.\nNhap x: ";
        cin>>Tx;
    }
    x=stof(Tx);

    cout<<"Nhap y: ";
    cin>>Ty;
    while (!KiemTraFloat(Ty)){
        cout<<"Vui long nhap lai.\nNhap y: ";
        cin>>Ty;
    }
    y=stof(Ty);
}

void cDiem::Xuat(){
    cout<<"("<<x<<","<<y<<")";
}

//tinh khoang cach giua 2 diem
float cDiem::KhoangCach(cDiem M) {
    return sqrt(pow(x - M.x, 2) + pow(y - M.y, 2));
}

//tinh tien 1 diem
void cDiem::TinhTien(float dx, float dy){
    x=x+dx;
    y=y+dy;
}

//quay 1 diem
void cDiem::Quay(cDiem M, float goc) {
    // doi tam M ve lai tam O, vector v = MO
    float dx=x-M.x;
    float dy=y-M.y;
    //ap dung cong thuc quay voi dx, dy
    float x_quay=dx*cos(goc)-dy*sin(goc);
    float y_quay=dx*sin(goc)+dy*cos(goc);

    //doi nguoc tam ve
    x=x_quay+M.x;
    y=y_quay+M.y;
}
// Phong to diem theo he so k voi tam vi tu bat ky
void cDiem::PhongTo(cDiem tam, float k) {
    x = tam.x + k * (x - tam.x);
    y = tam.y + k * (y - tam.y);
}

// Thu nho diem theo he so k voi tam vi tu bat ky
void cDiem::ThuNho(cDiem tam, float k) {
    if (k == 0) {
        cout << "Loi! He so thu nho khong the bang 0.\n";
        return;
    }
    // Thu nho chinh la phong to voi he so (1/k)
    x = tam.x + (x - tam.x) / k;
    y = tam.y + (y - tam.y) / k;
}
