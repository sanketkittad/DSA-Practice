#include<iostream>
using namespace std;
class Queue{
    int front;
    int rear;
    int size;
    int *a;
    public:
    Queue(int s){
        front=rear=-1;
        size=s;
        a=new int[size];
    }
    void enqueue(int data){
        if(rear=size-1){
            cout<<"Full\n";
            return;
        }
        else{
            a[++rear]=data;
        }
    }
    int dequeue(){
        if(front==rear){
            cout<<"Queue is empty\n";
            return -1;
        }
        else{
            int temp=a[(front++)+1];
            return temp;
        }
    }
    void display(){
        for(int i=front+1;i<=rear;++i){
            cout<<a[i]<<'\n';
        }
        cout<<'\n';
    }
};

int main(){
    cout<<"Enter size: ";
    int s;
    cin>>s;
    Queue q(s);
    while(1){
        cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter option: ";
        int op;
        cin>>op;
        switch (op)
        {
        case 1:
            int data;
            cout<<"Enter data: ";
            cin>>data;
            q.enqueue(data);
            break;
        case 2:
            cout<<q.dequeue()<<" was dequeued\n";
            break;
        case 3:
            q.display();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
}