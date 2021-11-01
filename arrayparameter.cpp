#include<iostream>
using namespace std;
int *arr(int s){
    int *p;
    p= new int[s];
    for(int i=0;i<s;++i)
    p[i]=i+1;
    return p;
}
int main(){
    int sz;
    cin>>sz;
    int *ptr=arr(sz);
    for(int i=0;i<sz;++i)
    cout<<ptr[i]<<endl;
    return 0;
}