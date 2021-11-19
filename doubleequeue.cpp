#include<iostream>
using namespace std;
class Node{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
    friend class DoubleQueueLL;    
};
class DoubleQueueLL{
    Node *front;
    Node *rear;
    public:
    DoubleQueueLL(){
        front=NULL;
        rear=NULL;
    }
    bool isEmpty(){
        return (front==NULL );
    }
    void enqueue(int data){
        Node *t=new Node(data);
        cout<<"1. Enter at front\n2. Enter at rear\nEnter option: ";
        int c;
        cin>>c;
        switch(c){
            case 1:
                if(isEmpty()){
                    front=rear=t;
                }
                else{
                    t->next=front;
                    front=t;
                }
                break;
            case 2:
                if(isEmpty()){
                    front=rear=t;
                }
                else{
                    rear->next=t;
                    rear=t;
                }
                break;            
        }
    }
    int dequeue(){
        
        cout<<"1. Delete at front\n2. Delete at rear\nEnter option: ";
        int c;
        cin>>c;
        switch(c){
            case 1:
                if(isEmpty()){
                    cout<<"Queue Empty\n";
                    return -1;
                }
                else{
                    Node *t=front;
                    front=front->next;
                    int d=t->data;
                    delete t;
                    return d;
                }
                break;
            case 2:
                if(isEmpty()){
                    cout<<"Queue Empty\n";
                    return -1;
                }
                else{
                    Node *t=front;
                    while(t->next!=NULL){
                        t=t->next;
                    }
                    Node *t1=rear;
                    int d=t1->data;
                    rear=t;
                    delete t1;
                    return d;
                }
                break;            
        }
        return -1;
    }
    void display(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
            }
            else{
                Node *t=front;
                while(t!=NULL){
                    cout<<t->data<<"<-";
                    t=t->next;
                }
                cout<<'\n';
            }
        }
};
int main(){
    DoubleQueueLL q;
    while(1){
        cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter Option: ";
        int c;
        cin>>c;
        switch(c){
            case 1:
                int d;
                cout<<"Enter data: ";
                cin>>d;
                q.enqueue(d);
                break;
            case 2:
                {
                    int t=q.dequeue();
                    if(t==-1)cout<<"Queue is empty\n";
                    else cout<<t<<" was dequeued\n";
                    break;
                }
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
        }
    }
}
