#include<iostream>
using namespace std;
struct Element{
    int r;
    int c;
    int data;
};
struct Sparse{
    int n;
    int m;
    int num;
    Element *e;
};
Sparse add(Sparse &s1,Sparse &s2){
    Sparse *sum=new Sparse();
    sum->num=s1.num+s2.num;
    sum->e=new Element[sum->num];
    int i,j,k;
    i=j=k=0;
    while(i<s1.num && j<s2.num){
        if(s1.e[i].r<s2.e[j].r){
            sum->e[k++].data=s1.e[i++].data;
        }
        else if(s1.e[i].r>s2.e[j].r){
            sum->e[k++].data=s2.e[j++].data;
        }
        else{
            if(s1.e[i].c>s2.e[j].c){
                sum->e[k++].data=s2.e[j++].data;
            }
            else if(s1.e[i].c<s2.e[j].c){
                sum->e[k++].data=s1.e[i++].data;
            }
            else{
                sum->e[k++].data=s1.e[i++].data+s2.e[j++].data;
            }
        }
    }
    for(;i<s1.num;++i){
        sum->e[k++].data=s1.e[i].data;
    }
    for(;j<s2.num;++j){
        sum->e[k++].data=s2.e[j].data;
    }
    sum->m=s1.m;
    sum->n=s2.n;
    sum->num=k;
    return *sum;
}
Sparse create(Sparse &s){
    cout<<"Enter number of rows: ";
    cin>>s.n;
    cout<<"\nEnter number of columns: ";
    cin>>s.m;
    cout<<"Enter number of elements: ";
    cin>>s.num;
    s.e=new Element[s.num];
    for(int i=0;i<s.num;++i){
        cout<<"Enter row: ";
        cin>>s.e[i].r;
        cout<<"Enter column: ";
        cin>>s.e[i].c;
        cout<<"Enter number: ";
        cin>>s.e[i].data;
    }
    return s;
}
void display(Sparse &s){
    int k=0;
    for(int i=0;i<s.n;++i){
        for(int j=0;j<s.m;++j){
            if(i==s.e[k].r && j==s.e[k].c){
                cout<<s.e[k].data<<' ';
                ++k;
            }
            else
                cout<<0<<' ';
        }
        cout<<'\n';
    }
}
int main(){
    int n,m;
    Sparse s;
    s=create(s);
    display(s);

}