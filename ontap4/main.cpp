#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct product
{
    string maHang;
    string tenHang;
    string dvt;
    float donGia;
    int soLuong;
    float thanhTien;
};


struct Node
{
    product infor;
    Node *next;
};

typedef Node* TRO;

void creat(TRO &L)
{
    L=NULL;
}

int empty(TRO L)
{
    return (L==NULL);
}



void nhapSP(product &p)
{
    cout<<"Ma hang:";
    cin.ignore();
    getline(cin,p.maHang);

    cout<<"ten hang:";
    getline(cin,p.tenHang);

    cout<<"don vi tinh:";
    getline(cin,p.dvt);

    cout<<"Don gia:";
    cin>>p.donGia;

    cout<<"so luong";
    cin>>p.soLuong;

    p.thanhTien = p.donGia * p.soLuong;
    cout<<"---------------------------------"<<endl;

}
// them vao cuoi danh sach
void add(TRO &L, product p)
{
    TRO Q, P;
    P = new Node;
    P->infor = p;
    P->next = NULL;

    if(empty(L))
        L =P;
    else 
    {
        Q = L;
        while(Q->next != NULL)
            Q=Q->next;
        Q->next = P;
    }

}

void inDS(TRO L)
{
    if (empty (L))
        cout<<"Empty!"<<endl;
    else
    {
        cout<<left<<setw(15)<<"Ma hang"
                  <<setw(15)<<"Ten hang"
                  <<setw(15)<<"Don vi tinh"
                  <<setw(15)<<"Don gia"
                  <<setw(15)<<"So luong"
                  <<setw(15)<<"Thanh tien"
                  <<endl;
        TRO Q = L;
        while (Q!= NULL)
        {
            product pp = Q->infor;
        cout<<left<<setw(15)<<pp.maHang
                  <<setw(15)<<pp.tenHang
                  <<setw(15)<<pp.dvt
                  <<setw(15)<<pp.donGia
                  <<setw(15)<<pp.soLuong
                  <<setw(15)<<pp.thanhTien
                  <<endl;
        
        
        Q = Q->next;
        }
    }
}

void del(TRO &L)
{
    TRO M, Q=L;
    int d=1;
    if(empty(L))
        cout<<"Empty!"<<endl;
    else{
        while(Q!=NULL && d<3)
        {
            M= Q;
            Q=Q->next;
            d++;
        }
        if(M!= NULL)
            M->next = Q->next;
        delete Q;
        
    }
}

void insert1(TRO &L, product p)
{
    TRO P = new Node;
    P->infor = p;
    P->next =L;
    L=P;


}
int main()
{
    TRO L;
    creat(L);

    int n;
    cout<<"Nhap so luong san pham:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        product p;
        nhapSP(p);
        add(L,p);
    }

    cout<<"===================Danh sach san pham============================="<<endl;
    inDS(L);

    del(L);
    cout<<"==================Danh sach sau xoa==============================="<<endl;
    inDS(L);

    product p1;
    nhapSP(p1);
    insert1(L, p1);

    cout<<"=========================Danh sach sau chen======================"<<endl;
    inDS(L);

}
