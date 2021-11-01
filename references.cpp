#include<iostream>
using namespace std;
int main(){
    int a=8; //integer value
    int &r=a; // this is a reference to the variable b
    
    int b=90; // this is another integer value
    cout<<a<<" is a. "<<r<<" is at place being refered by r. "<<b<<" is b. "<<endl; 
    r=b; // setting the variable being refered to by r to b
    cout<<a<<" is a. "<<r<<" is r. "<<endl;
    return 0;
    }