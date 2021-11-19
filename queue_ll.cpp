#include<iostream>
using namespace std;
class Node{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
    friend class QueueLL;    
};
class QueueLL{
    Node *front,*rear;
    public:
        QueueLL(){
            front=NULL;
            rear=NULL;
        }
        bool isEmpty(){
            return (front==NULL);
        }
        void enqueue(int data){
            Node *t=new Node(data);
            if(isEmpty()){
                front=t;
                rear=t;
            }
            else{
                rear->next=t;
                rear=t;
            }
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            else{
                int d=front->data;
                Node *t=front;
                front=front->next;
                t->next=NULL;
                delete t;
                return d;
            }
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
    QueueLL q;
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