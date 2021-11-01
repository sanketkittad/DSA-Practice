#include<iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
int main(){
    rectangle r{2,5};
    rectangle *p=&r;
    cout<<"Length: "<<p->length<<endl;
    cout<<"Breadth: "<<p->breadth<<endl;
    rectangle *p1= new rectangle;
    p1->breadth=2;
    p1->length=3;
    cout<<"Dynamic length: "<<p1->breadth<<endl;
    cout<<"Dynamic Breadth: "<<p1->length<<endl;
    return 0; 

}