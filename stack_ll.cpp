#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    Node *top;
    public:
    Stack();
    bool isEmpty();
    void push(int data);
    int pop();
    void display();
    int peek();
};
Stack::Stack(){
    top=NULL;
}

void Stack::push(int data){
    Node *t=new Node();
    t->data=data;
    if(top==NULL){
        top=t;
        top->next=NULL;
    }
    else{
        t->next=top;
        top=t;
    }
}
int Stack::pop(){
    if(top==NULL){
        cout<<"Stack underflow\n";
        return -1;
    }
    else{
        int temp=top->data;
        Node *nd=top;
        top=nd->next;
        delete nd;
        return temp;
    }
}
void Stack::display(){
    Node *t=top;
    if(t==NULL)cout<<"Stack underflow\n";
    while(t!=NULL){
        cout<<t->data<<' ';
        t=t->next;
    }
    cout<<'\n';
}
int Stack::peek(){
    if(top==NULL){
        cout<<"Stack underflow\n";
        return -1;
    }
    else{
        return top->data;
    }
}
int main(){
    Stack s;
     while(1){
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter option: ";
        int opt;
        cin>>opt;
        switch(opt){
            case 1:{
                int data;
                cout<<"Enter Data: ";
                cin>>data;
                s.push(data);
                break;
            }
            case 2:{
                int temp=s.pop();
                if(temp==-1){
                    break;
                }
                cout<<temp<<" was popped\n";
                break;
            }
            case 3:{
                cout<<s.peek()<<" is at the top\n";
                break;
            }
            case 4:{
                s.display();
                break;
            }
            case 5:{
                exit(0);
            }
        }
    }
}