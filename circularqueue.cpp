#include<iostream>
using namespace std;
class CircularQueue{
    int front;
    int rear;
    int size;
    int *a;
    public:
        CircularQueue(int s){
            front=rear=0;
            size=s+1;
            a=new int[size];
        }
        void enqueue(int data){
            if((rear+1)%size==front){
                cout<<"Queue Full\n";
                return;
            }
            else{
                rear=(rear+1)%size;
                a[rear]=data;
            }
        }
        int dequeue(){
            if(rear==front){
                cout<<"Empty Queue\n";
                return -1;
            }
            else{
                front=(front+1)%size;
                return a[front];
            }
        }
        void display(){
            int i = front + 1;
            do {
                cout << a[i];
                if (i < rear) {
                    cout << " <- " ;
                }
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout<<'\n';
        }
};
int main(){
    int s;
    cout<<"Enter Size needed: ";
    cin>>s;
    CircularQueue q(s);
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