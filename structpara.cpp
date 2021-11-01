#include<iostream>
using namespace std;
struct rect
{
    int n;
    int a[];
};
struct rect *ptr(int n1)
{
    struct rect *p;
    p=new rect;
    p->n=n1;
    for(int i=0;i<n1;++i)
    p->a[i]=i+1;
    return p;    
}
int main(){
    struct rect *r=ptr(5);
    cout<<r->n;
    for(int i=0;i<(r->n);++i)
    cout<<(r->a[i])<<endl;
    return 0;
}