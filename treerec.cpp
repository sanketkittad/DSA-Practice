#include<iostream>
using namespace std;
void rec(int n){
    if(n){
        cout<<n<<'\n';
        rec(n-1);
        rec(n-1);        
    }
}
int main(){
    int n=3;
    rec(3);
    return 0; 
}