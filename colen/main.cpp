#include <iostream>
#include <iomanip>
#include <string>

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

struct Node {
    SinhVien infor;
    Node * next;
};

typedef Node *TRO;


void creat (TRO &L)
{
    L = NULL;
}

int empty (TRO L)
{
    return (L==NULL);
}


void nhapSV(SinhVien &sv)
{
    cout<<"Ma sv:";
    cin.ignore();
    getline(cin,sv.maSV);

    cout<<"Ho dem:";
    getline(cin, sv.hoDem);

    cout<<"Ten:";
    getline(cin, sv.ten);

    cout<<"Gioi tinh:";
    getline(cin, sv.gioiTinh);

    cout<<"Nam sinh:";
    cin>>sv.namSinh;

    cout<<"Diem tk:";
    cin>>sv.diemTK;

    cout<<"-----------------------------------"<<endl;
}

void addSV(TRO &L, SinhVien sv)
{
    TRO P = new Node;
    P->infor = sv;
    P->next = NULL;

    if(empty(L))
        L = P;
    else 
    {
        TRO Q= L;
        while (Q->next!= NULL)
            Q=Q->next;
        Q->next = P;
    }
}

void inDS(TRO L)
{

    if (empty(L))
        cout<<"Empty!";

    else{
        cout<<left<<setw(15)<<"Ma sv"
                <<setw(15)<<"Ho dem"
                <<setw(15)<<"ten"
                <<setw(15)<<"Gioi tinh"
                <<setw(15)<<"Nam sinh"
                <<setw(15)<<"Diem tk"
                <<endl;
        TRO Q = L;
        while (Q!=NULL)
        {
            SinhVien sv = Q->infor;
            cout<<left<<setw(15)<<sv.maSV
                <<setw(15)<<sv.hoDem
                <<setw(15)<<sv.ten
                <<setw(15)<<sv.gioiTinh
                <<setw(15)<<sv.namSinh
                <<setw(15)<<sv.diemTK
                <<endl;
            Q= Q->next;        
        }

    }

}
void del(TRO &L)
{
    if (empty(L))
        cout<<"Empty!"<<endl;
    else
    {
        TRO Q = L;
        L = Q->next;
        Q->next = NULL;
    }
}


void chen(TRO&L, SinhVien sv, int k)
{
    TRO P= NULL;
    TRO Q = L;
    int d = 1;
    while (Q!= NULL and d<k)
    {
        P = Q;
        Q = Q->next;
        d++;
    }
    TRO M = new Node;
    M->infor = sv;
    M->next = P->next;
    P->next = M;
}
void sapC(TRO&L)
{
    if(empty(L))
        cout<<"Empty"<<endl;
    else
    {
        TRO MIN, I= L, J;
        while (I->next != NULL)
        {
            MIN = I;
            J= I->next;
            {
                while(J!= NULL)
                    {
                        if (J->infor.ten < MIN->infor.ten)
                        MIN = J;
                        SinhVien tg = I->infor;
                        I->infor = MIN->infor;
                        MIN->infor = tg;
                        J=J->next;
                    }

            }
            I=I->next;
        }
    }
}
void sapNB(TRO &L)
{
    if(empty(L))
        cout<<"Empty"<<endl;
    else{
        TRO I= L, J;
        while (I->next!= NULL)
        {
            J = I->next;
            while (J!=NULL)
            {
                if(I->infor.ten < J->infor.ten)
                {
                SinhVien tg = I->infor;
                I->infor = J->infor;
                J->infor = tg;
                
                }
                J=J->next;
            }
            I=I->next;
        }
    }
}
void searchTu(TRO L)
{
    if(empty(L))
        cout<<"Empty"<<endl;
    else{
        TRO Q =L;
        while (Q!= NULL)
        {
            if (Q->infor.ten=="Tu")
            {
                SinhVien sv = Q->infor;
            cout<<left<<setw(15)<<sv.maSV
                        <<setw(15)<<sv.hoDem
                        <<setw(15)<<sv.ten
                        <<setw(15)<<sv.gioiTinh
                        <<setw(15)<<sv.namSinh
                        <<setw(15)<<sv.diemTK
                        <<endl;    
            }
            Q=Q->next;

        }
    }
}
int main()
{
    TRO L;
    creat(L);

    cout<<"Nhap so sv:";
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        SinhVien sv;
        nhapSV(sv);
        addSV(L,sv);
    }
    cout<<"Danh sach sv"<<endl;
    inDS(L);


    // del(L);
    // cout<<"Danh sach sau xoa "<<endl;

    // inDS(L);
    
    // SinhVien ss;
    // nhapSV(ss);
    // chen(L,ss,3);
    // cout<<"Danh sach sau khi chen"<<endl;
    // inDS(L);


    // sapC(L);
    // sapNB(L);
    // cout<<"Danh sach sau sap:"<<endl;
    // inDS(L);

    

    searchTu(L);

}