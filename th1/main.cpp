#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define MAX 100
struct SinhVien
{
    string maSV;
    string ho;
    string ten;
    string gioiTinh;
    int namSinh;
    float diem;
};

struct vector
{
    int count;
    SinhVien sv[MAX];
};

int empty(vector v)
{
    return (v.count==-1);
}
void creat (vector &v)
{
    v.count=-1;
}
void xoa(vector &v)
{
    if(empty(v))
        cout<<"Mang rong!";
    else
    {
        for(int i=1;i<=v.count;i++)
            v.sv[i-1]=v.sv[i];
    }
    v.count--;
}
void nhapSV(SinhVien &sv)
{
    cout<<"MaSV:";
    cin.ignore();
    getline(cin,sv.maSV);

    cout<<"Ho dem:";
    getline(cin, sv.ho);

    cout<<"ten:";
    getline(cin,sv.ten);

    cout<<"GIoi tinh";
    getline(cin,sv.gioiTinh);

    cout<<"nam sinh:";
    cin>>sv.namSinh;

    cout<<"Diem tong ket:";
    cin>>sv.diem;


}

void add(vector &v,SinhVien sv ){
    if(v.count==MAX-1)
        cout<<"Danh sach day!";
    else
    {
        v.count++;
        v.sv[v.count]= sv;
    }
}
void inDS(vector v)
{
    cout<<"-------------------------Danh sach sinh vien------------------------------"<<endl;
    cout<<left<<setw(15)<<"Ma sv"<<setw(15)<<"Ho dem"<<setw(15)<<"ten"<<setw(15)<<"Gioi tinh"<<setw(10)<<"nam sinh"<<"Diem tk"<<endl;

    for(int i =0;i<=v.count;i++)
         cout<<left<<setw(15)<<v.sv[i].maSV<<setw(15)<<v.sv[i].ho<<setw(15)<<v.sv[i].ten<<setw(15)<<v.sv[i].gioiTinh<<setw(10)<<v.sv[i].namSinh<<v.sv[i].diem<<endl;

}
void insert(vector &v,SinhVien sv, int k)
{
    if(v.count==MAX-1)
        cout<<"ds day roi!";
    else
    {
        for(int i=v.count;i>=k-1;i--)
            v.sv[i+1]= v.sv[i];
            v.sv[k-1]=sv;
            v.count++;
    }
}
void sapTen(vector &v)
{
    for(int i=0;i<v.count;i++)
        for(int j=v.count;j>i;j--)
            if(v.sv[j].ten > v.sv[j-1].ten)
                {
                    SinhVien tg = v.sv[j];
                    v.sv[j]= v.sv[j-1];
                    v.sv[j-1]=tg;
                }
}
// void sapTen(vector &v)
// {
//     for (int i = 0; i < v.count; i++)
//         for (int j = v.count; j > i; j--)
//             if (v.sv[j].ten < v.sv[j-1].ten) // SẮP XẾP TĂNG DẦN
//             {
//                 SinhVien tg = v.sv[j];
//                 v.sv[j] = v.sv[j-1];
//                 v.sv[j-1] = tg;
//             }
// }






int main(){
    vector v;
    creat(v);

    cout<<"nhap so sv:";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        SinhVien s1;
        nhapSV(s1);
        add(v,s1);

    }
    
    inDS(v);
    // xoa(v);
    // inDS(v);

    // SinhVien s2;

    // nhapSV(s2);
    // insert(v,s2,3);

    // inDS(v);

    sapTen(v);
    inDS(v);
    



}
