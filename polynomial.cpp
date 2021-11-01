#include<iostream>
using namespace std;
struct Element{
    int exp;
    int coeff;
};
struct Polynomial{
    int n;
    Element *e;
};
Polynomial create(Polynomial &p){
    cout<<"Enter number of Terms: ";
    cin>>p.n;
    p.e=new Element[p.n];
    for(int i=0;i<p.n;++i){
        cout<<"Enter term "<<i+1<<':';
        cin>>p.e[i].coeff>>p.e[i].exp;
    }
    return p;
}
Polynomial add(Polynomial &p1,Polynomial &p2){
    int i,j,k;
    i=j=k=0;
    Polynomial sum;
    sum.n=p1.n+p2.n;
    while(i<p1.n && j<p2.n){
        if(p1.e[i].exp>p2.e[j].coeff){
            sum.e[k++]=p1.e[i++];
        }
        else if(p1.e[i].exp<p2.e[j].coeff){
            sum.e[k++]=p2.e[j++];
        }
        else{
            sum.e[k].exp=p1.e[i].exp;
            sum.e[k++].coeff=p1.e[i++].exp+p2.e[j++].exp;
        }
    }
    for(;i<p1.n;++i){
        sum.e[k++]=p1.e[i];
    }
    for(;j<p2.n;++j){
        sum.e[k++]=p2.e[j];
    }
    return sum;
}