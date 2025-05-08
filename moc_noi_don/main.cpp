#include<iostream>
#include<string>

using namespace std;

struct SinhVien{
    int id;
    string hoTen;
    int tuoi;
    float diemTK;
};

struct Node
{
    SinhVien infor;
    Node *next;
};
typedef Node* TRO;


// khoi tao danh sach rong
void creat(TRO &L)
{
    L=NULL;
}
// kiem tra rong?
int empty(TRO &L)
{
    return L== NULL;
}


// tao node tu sv
Node *
void nhapSV(SinhVien &sv)
{
    cout<<"ID:";
    cin>>sv.id;

    cout<<"Ho ten:";

    cin.ignore();
    getline(cin,sv.hoTen);

    cout<<"Tuoi:";
    cin>>sv.tuoi;

    cout<<"DiemTK:";
    cin>>sv.diemTK;
}

void inDS(TRO L)
{
    TRO Q;
    if (!=empty(L))
    while (Q!=NULL)
    {
        SinhVien X = Q->infor;
        cout<<X.id<<" "<<X.hoTen<<" "<<X.tuoi<<" "<<X.diemTK<<endl;
        Q->next;
    
    }
}


int main(){
    TRO L;
    cout<<empty(L);

}