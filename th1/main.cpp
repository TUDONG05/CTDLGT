#include<iostream>
#include<iomanip>
#include<string>

#define MAX 100

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

struct vector
{
    int count;
    SinhVien sv[MAX];
};
void creat(vector &v)
{
    v.count=-1;
}
int empty(vector v)
{
    return (v.count ==-1);
}

int full(vector v)
{
    return (v.count==MAX-1);
}

void nhapSV(SinhVien &sv)
{
    
    cout<<"Ma sv:";
    getline(cin,sv.maSV);

    cout<<"Ho dem:";
    getline(cin,sv.hoDem);

    cout<<"Ten:";
    getline(cin,sv.ten);

    cout<<"Gioi tinh:";
    getline(cin,sv.gioiTinh);

    cout<<"Nam sinh:";
    cin>>sv.namSinh;

    cout<<"Diem TK:";
    cin>>sv.diemTK;

}

void add(vector &v, SinhVien sv)
{
    if(full(v))
        cout<<"Danh sach da day!"<<endl;
    else
    {
        v.count++;
        v.sv[v.count] = sv;
    }
        
}

void addSV(vector &v, string maSV, string hoDem, string ten, string gioiTinh,int  namSinh, float diemtk)
{
    SinhVien sv;
    sv.maSV = maSV;
    sv.hoDem =hoDem;
    sv.ten = ten;
    sv.gioiTinh = gioiTinh;
    sv.namSinh= namSinh;
    sv.diemTK = diemtk;

    if(full(v))
        cout<<"DS day!"<<endl;
    else
        {
            v.count++;
            v.sv[v.count] = sv;
        }
}

void inDS(vector v)
{
    if(empty(v))
        cout<<"Danh sach rong!"<<endl;
    else
    {   cout<<left<<setw(10)<<"MaSV"
                  <<setw(15)<<"Ho dem"
                  <<setw(10)<<"Ten"
                  <<setw(15)<<"Gioi tinh"
                  <<setw(10)<<"Nam sinh"
                  <<setw(10)<<"Diem TK"<<endl;
        for(int i=0;i<=v.count;i++)
        cout<<left<<setw(10)<<v.sv[i].maSV
                    <<setw(15)<<v.sv[i].hoDem
                    <<setw(10)<<v.sv[i].ten
                    <<setw(15)<<v.sv[i].gioiTinh
                    <<setw(10)<<v.sv[i].namSinh
                    <<setw(10)<<v.sv[i].diemTK<<endl;
        cout<<"================================================================="<<endl;

    }
}

void del(vector &v)
{
    if(empty(v))
        cout<<"Danh sach rong!"<<endl;
    else
    {
        for(int i=0;i<v.count;i++)
            v.sv[i]=v.sv[i+1];
        v.count--;
        cout<<"Xoa thanh cong"<<endl;
    }
    
}

void chen(vector &v,string maSV, string hoDem, string ten, string gioiTinh,int  namSinh, float diemtk,int k)
{
    if(full(v))
        cout<<"Danh sach day!"<<endl;
    else
    {
        
        for(int i=v.count+1;i>=k-1;i--)
            v.sv[i+1] = v.sv[i];

        v.sv[k-1].maSV= maSV;
        v.sv[k-1].hoDem=hoDem;
        v.sv[k-1].ten=ten;
        v.sv[k-1].gioiTinh=gioiTinh;
        v.sv[k-1].namSinh=namSinh;
        v.sv[k-1].diemTK =diemtk;
        v.count++;
        cout<<"chen thanh cong!"<<endl;

    }
}


// sap chon de sap ten
void sapTen(vector &v)
{
    for(int i=0;i<=v.count-1;i++)
    {
        int m =i;
        for(int j=i+1;j<=v.count;j++)
        if(v.sv[j].ten<v.sv[m].ten)
            m = j;
        SinhVien tg = v.sv[i];
        v.sv[i]= v.sv[m];
        v.sv[m]= tg;
    }
    
    
}
int main()
{
    vector v;
    creat(v);
    
    addSV(v,"SV1001" ,"Tran Van","Thanh", "Nam", 1999 ,7.5);
    addSV(v,"SV1002", "Nguyen Thi","Huong" ,"Nu", 2000 ,7.3);
    addSV(v,"SV1003", "Nguyen Van", "Binh", "Nam" ,1998 ,6.4);
    addSV(v,"SV1004","Bui Thi","Hong","Nu",2000,6.4);
    addSV(v,"SV1005","Duong Van","Giang","Nam",1998,8.3);
    
    cout<<"====================Danh sach sinh vien=========================="<<endl;
    inDS(v);

    del(v);
    cout<<"==============Danh sach sinh vien sau khi xoa===================="<<endl;
    inDS(v);

    chen(v,"SV1006","Le Thi","Doan","Nu",1998,7.6,3);
    cout<<"==============Danh sach sinh vien sau khi chen==================="<<endl;
    inDS(v);

    sapTen(v);
    cout<<"==============Danh sach sau khi sap theo ten====================="<<endl;
    inDS(v);

}