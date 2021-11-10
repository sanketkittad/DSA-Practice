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
void evaluate(string postfix){
    stack<double> st;
    double temp=0;
    for(auto i: postfix){
        if(isOperand(i)){
            st.push(i-'0');
        }
        else{
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            switch (i)
            {
                case '*':
                    temp=a*b;
                    break;
                case '-':
                    temp=a-b;
                    break;
                case '+':
                    temp=a+b;
                    break;
                case '/':
                    temp=a/b;
                    break;
                default:
                    break;
            }
            st.push(temp);
        }
    }
    cout<<st.top();
}
int main(){
    string s;
    cin>>s;
    evaluate(s);
    return 0;
}