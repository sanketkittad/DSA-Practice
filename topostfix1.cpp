#include<iostream>
#include<stack>
#include<string>
using namespace std;
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}
 
int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}
 
int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}
string convert(string inf){
    stack<char> st;
    string ans="";
    // for(auto i:inf){
    //     if(!isOperand(i)){
    //         if(st.empty())
    //             st.push(i);
    //         else if(isOperand(i)){
    //             if(outPrecedence(i)>inPrecedence(st.top()))
    //                 st.push(i);
    //             else{
    //                 while(!st.empty() && inPrecedence(st.top())>=outPrecedence(i))
    //                 {
    //                     ans+=st.top();
    //                     st.pop();
    //                 }
    //                 st.push(i);
    //             }
    //         }
    //         else if(i==')'){
    //             while(st.top()!='('){
    //                 ans+=st.top();
    //                 st.pop();
    //             }
    //             st.pop();
    //         }
           
    //     } else
    //         ans+=i;
    // }
    for(auto i:inf){
        if(!isOperand(i)){
            if(st.empty())
                st.push(i);
            else if(outPrecedence(i)>inPrecedence(st.top()))
                st.push(i);
            else {
                while(!st.empty() && outPrecedence(i)<inPrecedence(st.top())){
                    ans+=st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        else if(i==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        ans+=i;
    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<convert(s);
    return 0;
}