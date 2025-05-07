#include <iostream>
#include<iomanip>
#include <string>
#define MAX 100

using namespace std;
struct SinhVien
{
    string hoTen;
    string gioiTinh;
    int namSinh;
    float diemTK;
};

void nhapds(SinhVien SV[], int n)
{

    for(int i=0;i<n;i++)
    {
        cin.ignore();

        cout<<"nhap thong tin sv thu "<<i+1<<endl;

        cout<<"Ho ten:";
        getline(cin,SV[i].hoTen);


        cout<<"Gioi tinh:";
        getline(cin,SV[i].gioiTinh);

        cout<<"Nam sinh:";
        cin>>SV[i].namSinh;

        cout<<"Diem TK:";
        cin>>SV[i].diemTK;
    }
}


void inds(SinhVien SV[], int n)
{
    cout<<"---------------------------Danh sach sinh vien----------------------------------------"<<endl;
    cout<<left <<setw(30)<<"Ho ten"<<setw(15)<<"Gioi Tinh"<<setw(15)<<"Nam sinh"<<setw(10)<<"DiemTK"<<endl;
    for(int i=0;i<n;i++)
      cout<<left<<setw(30)<<SV[i].hoTen<<setw(15)<<SV[i].gioiTinh<<setw(15)<<SV[i].namSinh<<setw(10)<<SV[i].diemTK<<endl;
    cout<<"--------------------------------------------------------------------------------------"<<endl;

}
int tkten(SinhVien SV[], int n, string ten)
{
    int i=0;
    while(i<n && SV[i].hoTen!=ten)
        i++;
    if(i<n)
        return i;
    else
        return -1;
}
int timkiem(SinhVien SV[], int n, string ten)
{
    for(int i=0;i<n;i++)
        if(SV[i].hoTen==ten)
            return i;
    return -1;
}
int timdiem(SinhVien SV[], int left, int right, float diem)
{
    if(left>right )
        return -1;
    else
    {
        int mid = (left+right)/2;
        if(SV[mid].diemTK==diem)
            return mid;
        else if (SV[mid].diemTK>diem)
            return timdiem(SV,left,mid-1,diem);
        else
            return timdiem(SV,mid+1,right,diem);
    }
}
int main()
{

    SinhVien SV[MAX];
    int n;
    cout<<"nhap so sv:";
    cin>>n;

    nhapds(SV,n);
    inds(SV,n);

    /*string ten;
    cout<<"nhap ten muon tim:";

    cin.ignore();
    getline(cin,ten);


    int tim = timkiem(SV,n,ten);
    if(tim!=-1)
    {
        cout<<"Da tim thay sinh vien"<<endl;
        cout<<left<<setw(30)<<SV[tim].hoTen<<setw(15)<<SV[tim].gioiTinh<<setw(15)<<SV[tim].namSinh<<setw(10)<<SV[tim].diemTK<<endl;
    }

    else
        cout<<"khong tim thay";
    */

    float diem;
    cout<<"nhap diem:";
    cin>>diem;

    int tim = timdiem(SV,0,n-1,diem);
    if(tim!=-1)
    {
        cout<<"Da tim thay sinh vien"<<endl;
        cout<<left<<setw(30)<<SV[tim].hoTen<<setw(15)<<SV[tim].gioiTinh<<setw(15)<<SV[tim].namSinh<<setw(10)<<SV[tim].diemTK<<endl;
    }

    else
        cout<<"khong tim thay";
}
