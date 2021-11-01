#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="ellowwooddoor";
    long int h=0;
    for(int i=0;i<s.size();++i){
        int x=1;
        x<<(s[i]-97);
        if(x&h>0){
            cout<<s[i]<<"repeated\n";
        }
        else{
            h|=x;
        }
    }
}