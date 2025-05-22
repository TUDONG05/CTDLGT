#include <iostream>
#include <string>
#include <iomanip>
#define MAX  100
using namespace std;


struct SinhVien
{
    string maSV;
    string hoDem;
    string ten;
    string gioiTinh;
    int namSinh;
    float diemTK;
};

struct List
{
    int count;
    SinhVien sv[MAX];
};
void create(List &L)
{
    L.count =-1;
}

int empty(List L)
{
    return (L.count ==-1);
}

int full(List L)
{
    return (L.count ==MAX -1);
}
void nhapSV(SinhVien &sv)
{
    cout<<"Ma sv:";
    cin.ignore();
    getline(cin,sv.maSV);

    cout<<"Ho dem:";
    getline(cin,sv.hoDem);

    cout<<"ten:";
    getline(cin,sv.ten);

    cout<<"Gioi tinh:";
    getline(cin, sv.gioiTinh);

    cout<<"Nam sinh:";
    cin>>sv.namSinh;

    cout<<"Diem tk:";
    cin>>sv.diemTK;

    cout<<"--------------------------------"<<endl;
    
}
void addSV(List &L, SinhVien sv)
{
    if(full(L))
        cout<<"Danh sach day!"<<endl;
    else 
    {
        L.count++;
        L.sv[L.count] = sv;
    }

}

void inDS(List L)
{
    cout<<left<<setw(15)<<"Ma sv"
              <<setw(15)<<"Ho dem"
              <<setw(15)<<"ten"
              <<setw(15)<<"gioi tinh"
              <<setw(15)<<"nam sinh"
              <<setw(15)<<"diem tk"
              <<endl;
    for(int i=0;i<=L.count;i++)
        cout<<left<<setw(15)<<L.sv[i].maSV
              <<setw(15)<<L.sv[i].hoDem
              <<setw(15)<<L.sv[i].ten
              <<setw(15)<<L.sv[i].gioiTinh
              <<setw(15)<<L.sv[i].namSinh
              <<setw(15)<<L.sv[i].diemTK
              <<endl;
    
}

void xoa1(List &L)
{
    for(int i=0;i<L.count;i++)
        L.sv[i]= L.sv[i+1];
    L.count --;
}
void chen(List &L, SinhVien sv, int k)
{
    for(int i=L.count;i>=k-1;i--)
    {
        L.sv[i+1] = L.sv[i]; 
    }
    L.sv[k-1]= sv;
    L.count++;


}

void sapC(List &L)
{
    for(int i=0;i<L.count;i++)
        {
            int min = i;
            for(int j=i+1;j<L.count;j++)
            {
                if(L.sv[j].ten< L.sv[min].ten)
                    min = j;


            }
            SinhVien tg = L.sv[i];
            L.sv[i]=L.sv[min];
            L.sv[min]= tg;

        }
}
int main()
{
    List L;
    create(L);
    int n;
    cout<<"Nhap so luong sv:";
    cin>>n;
    for(int i=0;i<n;i++)
        {
            SinhVien sv;
            nhapSV(sv);
            addSV(L,sv);
        }
    
    cout<<"=====================DANH SACH SINH VIEN========================"<<endl;
    inDS(L);

    cout<<"=====================DANH SACH SAU XOA========================"<<endl;
    xoa1(L);
    inDS(L);

    
    SinhVien ss ;
    nhapSV(ss);
    chen(L,ss,3);
    cout<<"=====================DANH SACH SAU XOA========================"<<endl;
    inDS(L);

    cout<<"=====================DANH SACH SAU SAP========================"<<endl;
    sapC(L);
    inDS(L);
}