#include<iostream>
#include<iomanip>
#include<string>
#define MAX 100
using namespace std;
// định nghĩa cấu trúc 1 sinh viên
struct SinhVien
{
    string maSV;
    string hoDem;
    string ten;
    string gioiTinh;
    int namSinh;
    float diemTK;
};
// định nghĩa cấu trúc 1 node
struct Node
{
    SinhVien infor;
    Node * next;
};
typedef Node * TRO;

void creat(TRO &L)
{
    L =NULL;
}

int empty(TRO L)
{
    return (L==NULL);
}


// nhap sinh vien
void nhapSV(SinhVien &sv)
{
    cout<<"Ma sinh vien:";
    cin.ignore();

    getline(cin,sv.maSV);

    cout<<"Ho dem:";
    getline(cin,sv.hoDem);

    cout<<"Ten:";
    getline(cin,sv.ten);


    cout<<"Gioi tinh:";
    getline(cin,sv.gioiTinh);

    cout<<"Nam sinh";
    cin>>sv.namSinh;

    cout<<"Diem tk:";
    cin>>sv.diemTK;
}
// thêm 1 sinh viên vào danh sách
void add(TRO &L, SinhVien sv)
{
    TRO Q, P;

    P = new Node;
    P->infor = sv;
    P->next = NULL;

    if (L == NULL)
        L = P;
    else
    {
        Q = L;
        while (Q->next != NULL)  // Duyệt đến nút cuối
            Q = Q->next;
        Q->next = P;
    }
}

// them vao dau danh sach
// void addToHead(TRO &L, SinhVien sv)
// {
//     TRO P = new Node;
//     P->infor = sv;
//     P->next = L;
//     L = P;
// }

// lay do dai
int Length(TRO L)
{
    int count =0 ;
    TRO Q=L;
    while(Q!=NULL)
    {
        Q=Q->next;
        count ++;
    }
    return count;
}
// in danh sach
void inDS(TRO L)
{
    if(empty(L))
        cout<<"Danh sach rong!"<<endl;

    else
        {
            cout<<left<<setw(10)<<"MaSV"
                    <<setw(15)<<"Ho dem"
                    <<setw(10)<<"Ten"
                    <<setw(15)<<"Gioi tinh"
                    <<setw(10)<<"Nam sinh"
                    <<setw(10)<<"DiemTK"
                    <<endl;
        }
    TRO Q = L;
    while(Q!=NULL)
    {
        SinhVien sv = Q->infor;
        cout<<left<<setw(10)<<sv.maSV
                    <<setw(15)<<sv.hoDem
                    <<setw(10)<<sv.ten
                    <<setw(15)<<sv.gioiTinh
                    <<setw(10)<<sv.namSinh
                    <<setw(10)<<sv.diemTK
                    <<endl;
        Q=Q->next;

    }
    cout<<"========================================================================"<<endl;


}
// xoa phan tu dau tien
void del_first(TRO &L)
{
    if(empty(L))
        cout<<"Danh sach rong!"<<endl;
    else
    {
        TRO Q = L;
        L=L->next;
        delete Q;
    }

}
void chen(TRO &L, SinhVien sv, int k)
{
    int dem =0;
    TRO M,Q =L;
    while(Q!=NULL and dem <k-1)
    {
        M=Q;
        Q=Q->next;
        dem++;
    }
    if(Q==NULL)
    {
        cout<<"Vi tri chen khong thich hop! "<<endl;

    }
    TRO P = new Node;
    P->infor.maSV = sv.maSV;
    P->infor.hoDem = sv.hoDem;
    P->infor.ten = sv.ten;
    P->infor.gioiTinh = sv.gioiTinh;
    P->infor.namSinh = sv.namSinh;
    P->infor.diemTK = sv.diemTK;

    P->next = M->next;
    M->next = P;
}
int main()
{
    TRO L;
    creat(L);
    int n;
    cout<<"Nhap so luong sv";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        SinhVien sv;
        nhapSV(sv);
        add(L,sv);
    }
    
    inDS(L);
    del_first(L);
    cout<<"Danh sach sau khi xoa:"<<endl;
    inDS(L);

    int k ;
    cout<<"Nhap vi tri muon chen:";
    cin>>k;

    SinhVien ss ;
    nhapSV(ss);
    chen(L,ss,3);

    cout<<"Danh sach sau khi chen:"<<endl;
    inDS(L);
}

