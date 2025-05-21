#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct CanBo
{
    string maCB;
    string hoDem;
    string ten;
    string gioiTinh;
    int tuoi;
    float hsLuong;
    long long luongCB;
};

struct Node 
{
    CanBo infor;
    Node *next;
};

typedef Node *TRO;

void creat(TRO &L)
{
    L=NULL;
}

int empty(TRO L)
{
    return (L==NULL);
}

void nhapCB(CanBo &cb)
{
    cout<<"Ma cb:";
    cin.ignore();
    getline(cin,cb.maCB);

    cout<<"Ho dem:";
    getline(cin,cb.hoDem);

    cout<<"ten:";
    getline(cin,cb.ten);

    cout<<"gioi tinh:";
    getline(cin,cb.gioiTinh);

    cout<<"tuoi:";
    cin>>cb.tuoi;

    cout<<"he so luong:";
    cin>>cb.hsLuong;

    cb.luongCB = cb.hsLuong * 1490000;
    cout<<"------------------------------------------"<<endl;
}

void add(TRO &L, CanBo cb)
{
    TRO P,Q ;
    P = new Node;
    P->infor = cb;
    P->next = NULL;

    if(empty(L))
        L = P;
    else 
    {
        Q = L;
        while(Q->next!=NULL)
            Q=Q->next;
        Q->next = P;
    }

}
void inDS(TRO L)
{
    cout<<left<<setw(15)<<"Ma cb"
              <<setw(15)<<"Ho dem"
              <<setw(15)<<"ten"
              <<setw(15)<<"gioi tinh"
              <<setw(15)<<"tuoi"
              <<setw(15)<<"he so luong"
              <<setw(15)<<"Luong co ban"
              <<endl;


    TRO Q = L;
    while(Q!= NULL)
    {
            CanBo cb = Q->infor;
            cout<<left<<setw(15)<<cb.maCB
              <<setw(15)<<cb.hoDem
              <<setw(15)<<cb.ten
              <<setw(15)<<cb.gioiTinh
              <<setw(15)<<cb.tuoi
              <<setw(15)<<cb.hsLuong
              <<setw(15)<<cb.luongCB
              <<endl;
            
            Q=Q->next;
    }
}
void cbNU(TRO L)
{
    TRO Q = L;
    while (Q->next !=NULL)
    {   
        CanBo cb = Q->infor;
        if(cb.gioiTinh =="Nu" && cb.tuoi <=50)
        {
            cout<<left<<setw(15)<<cb.maCB
              <<setw(15)<<cb.hoDem
              <<setw(15)<<cb.ten
              <<setw(15)<<cb.gioiTinh
              <<setw(15)<<cb.tuoi
              <<setw(15)<<cb.hsLuong
              <<setw(15)<<cb.luongCB
              <<endl;     
        }
        Q=Q->next;

  
    }
}
void searchTung(TRO L)
{
    TRO Q = L;
    while (Q->next !=NULL)
    {   
        CanBo cb = Q->infor;
        int d=0;
        if(cb.ten =="Tung")
        {
            cout<<left<<setw(15)<<cb.maCB
              <<setw(15)<<cb.hoDem
              <<setw(15)<<cb.ten
              <<setw(15)<<cb.gioiTinh
              <<setw(15)<<cb.tuoi
              <<setw(15)<<cb.hsLuong
              <<setw(15)<<cb.luongCB
              <<endl;   
            d++;  
        }
        if(d>0)
            return;
        Q=Q->next;

    // 
    }
    cout<<"ko tim thay"<<endl;

}


void insertK(TRO &L, CanBo cb,int k)
{
    int i=1;
    TRO P = NULL;
    TRO Q = L;
    while(Q!= NULL && i<=k)
    {
        P= Q;
        Q=Q->next;
        i++;
    }
    TRO M = new Node;
    M->infor = cb;
    M->next = P ->next;
    P->next= M;
    
}
void del3(TRO &L, int k)
{
    TRO P = NULL;
    TRO Q = L;
    int i= 1;
    while(Q != NULL && i<k)
    {
        P = Q;
        Q = Q->next;
        i++;
    }
    P->next = Q->next;
    delete Q;


}
void add1(TRO &L, CanBo cb)
{
    TRO P = new Node;

    P->infor = cb;
    P->next = L;

    L= P;

}


void sapChon(TRO &L)
{
    TRO MIN,I=L,J;
    while(I->next!=NULL)
    {
        MIN = I;
        J = I->next;

        while(J!=NULL)
        {
            if(J->infor.ten < MIN->infor.ten)
                MIN = J;
            J=J->next;
            
            
        }
        CanBo tg = I->infor;
        I->infor = MIN->infor;
        MIN->infor = tg;
        I=I->next;

    }
}

void sapBot(TRO &L)
{
    TRO I=L, J;
    while (I->next != NULL)
    {
        J = I->next;
        while(J != NULL)
        {
        if (I->infor.ten < J->infor.ten)
            {
                CanBo tg = I->infor;
                I->infor = J->infor;
                J->infor = tg;
            }  
        J=J->next;          
        }

        I= I->next;
    }

}



int main()
{
    TRO L;
    creat(L);

    int n;
    cout<<"Nhap so cb:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        CanBo cb;
        nhapCB(cb);
        add(L, cb);
    }

    cout<<"==============Danh sach can bo================="<<endl;
    inDS(L);

    // cout<<"======Danh sach can bo nu <=50 tuoi============"<<endl;
    // cbNU(L);

    // cout<<"===========Ket qua tim can bo ten Tung=========="<<endl;
    // searchTung(L);

    // CanBo t;
    // nhapCB(t);

    // insertK(L,t,3);
    // add1(L,t);
    // cout<<"============Danh sach sau khi chen==================="<<endl;
    // inDS(L);

    // del3(L,3);
    // cout<<"==============Danh sach sau xoa========================"<<endl;
    // inDS(L);
    // sapChon(L);
    sapBot(L);
    cout<<"======Danh sach sau sap===================="<<endl;
    inDS(L);
    
}