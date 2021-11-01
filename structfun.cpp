#include<iostream>
using namespace std;
struct rect
{
    int length;
    int breadth;
};
void set(rect *r, int l,int b){
    r->length=l;
    r->breadth=b;
}
int area(rect r)
{
    return r.length*r.breadth;
}
void change(rect *r, int l){
    r->length=l;
}
int main(){
    rect r;
    set(&r,10,20);
    cout<<area(r)<<endl;
    change(&r,20);
    cout<<area(r)<<endl;
    return 0;
}