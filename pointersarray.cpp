#include<iostream>
using namespace std;
int main(){
    int a[5]={2,4,5,6,6};
    int *p=a;
    for(int i=0;i<5;++i)
        cout<<p[i]<<endl;
    int *np= new int[5];
    np[0]=1,np[1]=4,np[2]=9,np[3]=9,np[4]=91;
    for(int i=0;i<5;++i)
        cout<<np[i]<<endl;
    delete []np;
    return 0;
}