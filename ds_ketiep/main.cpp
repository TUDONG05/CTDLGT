#include<iostream>
#include<string>
#include<iomanip>
#define MAX 100
using namespace std;

struct SinhVien
{
    string name;
    int age;
};

struct List
{
    int count;
    SinhVien sv[MAX];

};

void creat(List &L)
// tao list rong
{
    L.count=-1;
}

// kiem tra list rong?
int empty(List L)
{
    return (L.count==-1);
}

// kiem tra list day?
int full(List L)
{
    return (L.count == MAX-1);
}


// them mot phan tu vao cuoi danh sach
int add(List &L, SinhVien s)
{
    if(full(L))
        return 0;
    else
    {
        L.count++;
        L.sv[L.count]= s;
        return 1;
    }
}

// nhap thong tin 1 sv
void nhapTT(SinhVien &sv)
{
    cout<<"Ho ten:";
    // cin.ignore();
    getline(cin,sv.name);

    cout<<"Tuoi:";
    cin>>sv.age;

}
// in ra danh sach
void inDS(List L)
{
    cout<<"--------Danh sach sinh vien--------"<<endl;
    cout<<left<<setw(30)<<"Ho ten"<<setw(15)<<"Tuoi"<<endl;
    for(int i=0;i<=L.count;i++)
    cout<<left<<setw(30)<<L.sv[i].name<<setw(15)<<L.sv[i].age<<endl;
}
// xoa phan tu o vi tri thu k
void del(List &L, int k)
{
    if(k>1 && k<=L.count+1)
    {
        for(int i=k;i<=L.count;i++)
            L.sv[i-1]=L.sv[i];
        L.count--;
    }
    else
        cout<<"ko xoa duoc"<<endl;

    
}
void insert(List &L, int k,SinhVien s)
{
    if(full(L))
        cout<<"Mang da day!Ko the chen!"<<endl;
    else
    {
        for(int i=L.count;i>=k-1;i--)
            L.sv[i+1]=L.sv[i];

        L.sv[k-1]=s;
        L.count++;
    }
}

int main()
{
    List L;
    creat(L);
    
    int n;
    cout<<"nhap so sv:";
    cin>>n;
for(int i=0;i<n;i++)
{
    SinhVien s;
    cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
    cin.ignore();

    nhapTT(s);
    add(L,s);
}

    inDS(L);

    // int k= 2;
    // del(L,k);
    // inDS(L);

    SinhVien s1 ;
    cin.ignore();
    nhapTT(s1);
    insert(L,2,s1);
    inDS(L);





}