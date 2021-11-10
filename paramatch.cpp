#include<iostream>
#include <stack>
using namespace std;
bool match(string s,stack<char> &st){
    for(auto i:s){
        if(i=='(')
        st.push('(');
        else if(i==')')
        st.pop();
        else
        continue;
    }
    return st.empty();
}
int main(){
    stack<char> st;
    string s="(a*b)+(a+b)";
    bool ans=match(s,st);
    if(ans)cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}