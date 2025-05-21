#include<iostream>
#include<iomanip>
#include<string>
#define MAX 100

using namespace std; 

struct CanBo 
{
    string maCanBo;
    string hoDem;
    string ten;
    string gioiTinh;
    int tuoi;
    float heSoLuong;
    float luongCoBan;


};
struct List 
{
    int count;
    CanBo cb[MAX];
};

void creat(List&L)
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

void nhapCB(CanBo &cb)
{
    cin.ignore();
    cout<<"Ma can bo:";
    getline(cin,cb.maCanBo);

    cout<<"Ho dem";
    getline(cin,cb.hoDem);

    cout<<"ten:";
    getline(cin,cb.ten);

    cout<<"gioi tinh:";
    getline(cin,cb.gioiTinh);

    cout<<"tuoi:";
    cin>>cb.tuoi;

    cout<<"he so luong:";
    cin>>cb.heSoLuong;

    cb.luongCoBan = cb.heSoLuong *1490;

    cout<<"-----------------------"<<endl;
}


void add(List &L, CanBo cb)
{

    if (full(L))
        cout<<"Danh sach da day!"<<endl;
    else{
        L.count ++;
        L.cb[L.count] = cb;

    }

}


void inDS(List L)
{
    cout<<left<<setw(10)<<"Ma cb"
                <<setw(15)<<"Ho dem"
                <<setw(10)<<"ten"
                <<setw(10)<<"Gioi tinh"
                <<setw(15)<<"tuoi"
                <<setw(25)<<"he so luong"
                <<setw(25)<<"Luong co ban"
                <<endl;

    for(int i=0;i<=L.count;i++)
        cout<<left<<setw(10)<<L.cb[i].maCanBo
                <<setw(15)<<L.cb[i].hoDem
                <<setw(10)<<L.cb[i].ten
                <<setw(10)<<L.cb[i].gioiTinh
                <<setw(15)<<L.cb[i].tuoi
                <<setw(25)<<L.cb[i].heSoLuong
                <<setw(25)<<L.cb[i].luongCoBan
                <<endl;
}
void cbn(List L)
{
    cout<<left<<setw(10)<<"Ma cb"
                <<setw(15)<<"Ho dem"
                <<setw(10)<<"ten"
                <<setw(10)<<"Gioi tinh"
                <<setw(15)<<"tuoi"
                <<setw(25)<<"he so luong"
                <<setw(25)<<"Luong co ban"
                <<endl;

    for(int i=0;i<=L.count;i++)
        if(L.cb[i].gioiTinh =="Nu" && L.cb[i].tuoi <=50)
            cout<<left<<setw(10)<<L.cb[i].maCanBo
                <<setw(15)<<L.cb[i].hoDem
                <<setw(10)<<L.cb[i].ten
                <<setw(10)<<L.cb[i].gioiTinh
                <<setw(15)<<L.cb[i].tuoi
                <<setw(25)<<L.cb[i].heSoLuong
                <<setw(25)<<L.cb[i].luongCoBan
                <<endl;
}

void searchTung(List L)
{
    int d =0;
    for(int i=0;i<=L.count ;i++)
        if(L.cb[i].ten =="Tung")
        {
            cout<<left<<setw(10)<<L.cb[i].maCanBo
                <<setw(15)<<L.cb[i].hoDem
                <<setw(10)<<L.cb[i].ten
                <<setw(10)<<L.cb[i].gioiTinh
                <<setw(15)<<L.cb[i].tuoi
                <<setw(25)<<L.cb[i].heSoLuong
                <<setw(25)<<L.cb[i].luongCoBan
                <<endl; 
            d++;
            break;
        }
        if(d==0)
            cout<<"khong co can bo ten tung!";


}

void insert(List &L, CanBo cb)
{
    if(full(L))
        cout<<"Full!";
    else{
        for(int i=L.count;i>=3;i--)
        L.cb[i+1]= L.cb[i];
        L.count ++;

    }

}
int main (){
    List L;
    creat(L);

    int n;
    cout<<"nhap so luong can bo:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        CanBo cb;
        nhapCB(cb);
        add(L,cb);
    }

    cout<<"===============Danh sach can bo=========================="<<endl;
    inDS(L);

    cout<<"==============Danh sach can bo nu tu 50 tro xuong=========="<<endl;
    cbn(L);
    cout<<"==============ket qua tim kiem can bo ten Tung============================="<<endl;
    searchTung(L);


    
    CanBo cc ;
    nhapCB(cc);
    insert(L,cc);
    cout<<"Danh sach sau khi chen 1 phan tu vao sau phan tu thu 3: "<<endl;
    inDS(L);
}



