#include<iostream>
using namespace std;
void rec(int x){
    if(x){
        rec(x-1);
        cout<<x<<'\n';
    }
}
int main(){
    int x=3;
    rec(x);
    return 0;
}