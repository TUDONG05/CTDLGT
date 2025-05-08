#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct SinhVien
{
    string hoTen;
    string gioiTinh;
    int namSinh;
    float diemTK;
};

void nhapSV(SinhVien sv[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Nhập thông tin sinh viên thứ "<<i<<endl;

        cin.ignore();
        cout<<"Họ tên:";
        getline(cin,sv[i].hoTen);

        cout<<"Giới tính:";
        getline(cin,sv[i].gioiTinh);

        cout<<"Năm sinh:";
        cin>>sv[i].namSinh;

        cout<<"Điểm tổng kết:";
        cin>>sv[i].diemTK;

    }
}
void inSV(SinhVien sv[], int n)
{
    cout<<"----------------------------------Danh sách sinh viên:------------------------------------------"<<endl;
    cout<<left<<setw(30)<<"Họ tên:"<<setw(20)<<"Giới tính:"<<setw(20)<<"Năm sinh:"<<setw(10)<<"Điểm tổng kết:"<<endl;
    for(int i=0;i<n;i++)
        cout<<left<<setw(30)<<sv[i].hoTen<<setw(20)<<sv[i].gioiTinh<<setw(20)<<sv[i].namSinh<<setw(10)<<sv[i].diemTK<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
}

int tktt(SinhVien sv[], int n, string ten)
{
    int i=0;
    while (i<n && sv[i].hoTen!=ten)
        i++;
    if(i<n)
        return i;
    else
        return -1;

    
}


int main()
{
    int n;
    cout<<"Nhập số lượng sinh viên:";
    cin>>n;
    SinhVien *sv = new SinhVien[n];
    nhapSV(sv,n);
    inSV(sv,n);

    string ten;
    cin.ignore();
    cout<<"Nhập tên muốn tìm:";
    getline(cin,ten);

    int tim = tktt(sv,n,ten);
    if (tim != -1)
        {
            cout<<"Đã tìm thấy sinh viên:"<<endl;
            cout<<left<<setw(30)<<sv[tim].hoTen<<setw(20)<<sv[tim].gioiTinh<<setw(20)<<sv[tim].namSinh<<setw(10)<<sv[tim].diemTK<<endl;
        }
    else 
        cout<<"Không tìm thấy kết quả!";
}
