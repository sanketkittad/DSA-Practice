#include<iostream>
using namespace std;
void perm(string s,int k){
    static int gets[4];
    static char res[4];
    int i;
    if(k==3){
        s[k]='\0';
        cout<<res<<' ';
    }
    else{
       
        for(i=0;i<3;++i){
            if(gets[i]==0){
                res[k]=s[i];
                gets[i]=1;
                perm(s,k+1);
                gets[i]=0;
            }
        }
    }

}
void subs(string s,int i,string ans){
    if(i==s.size()){
        cout<<ans<<' ';
        return;
    }
    subs(s,i+1,ans+s[i]);
    subs(s,i+1,ans);
}
int main(){
    string s="abc";
    string ans="";
    perm(s,0);
    return 0;
}