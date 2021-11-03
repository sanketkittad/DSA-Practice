#include<iostream>
using namespace std;
struct Stack{
    int top;
    int size;
    int *s;    
};
bool checkEmpty(Stack *s){
    return s->top==-1;
}
bool checkFull(Stack *s){
    if(s->top==s->size-1)
        return true;
    else 
        return false;
}
void create(Stack *st){
        cout<<"Enter size of stack needed: ";
        cin>>st->size;
        st->s=new int[st->size];
        st->top=-1;
}
void push(Stack *st,int data){
    if(checkFull(st))
        {
            cout<<"Stack overflow\n";
        }
   
    else{
        st->s[++st->top]=data;
    }
}
int pop(Stack *s){
    if(checkEmpty(s)){
            cout<<"Stack underflow\n";
            return -1;
        }
    else{
        int temp=s->s[s->top--];
        --s->size;
        s->top;
        return temp;
    }
}
int peek(Stack *s){
    if(checkEmpty(s)){
        cout<<"Stack underflow\n";
        return -1;
    }
    else{
        return s->s[s->top];
    }
}
void display(Stack *s){
    for(int i=s->top;i>=0;--i)cout<<s->s[i]<<' ';
    cout<<'\n';
}
int main(){
    Stack s;
    create(&s);
    while(1){
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter option: ";
        int opt;
        cin>>opt;
        switch(opt){
            case 1:{
                int data;
                cout<<"Enter Data: ";
                cin>>data;
                push(&s,data);
                break;
            }
            case 2:{
                int temp=pop(&s);
                if(temp==-1){
                    break;
                }
                cout<<pop(&s)<<" was popped\n";
                break;
            }
            case 3:{
                cout<<peek(&s)<<" is at the top\n";
                break;
            }
            case 4:{
                exit(0);
            }
        }
    }
    return 0;
}