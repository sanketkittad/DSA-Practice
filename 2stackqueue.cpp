#include<iostream>
#include<stack>
using namespace std;
class TwoStackQueue{
    stack<int> s1,s2;
    public:
    void enqueue(int data){
        s1.push(data);
    }
    int dequeue(){
        if(s2.empty()){
            while(!s1.empty()){
                int d=s1.top();
                s2.push(d);
                s1.pop();
            }
            if(s1.empty()){
                cout<<"Queue empty\n";
                return -1;
            }
        }
        int d=s2.top();
        s2.pop();
        return d;
    }
    void display()
    {
        if(s2.empty()){
            while(!s1.empty()){
                int d=s1.top();
                s2.push(d);
                s1.pop();
            }
            if(s1.empty()){
                cout<<"Queue empty\n";
                return;
            }
        }
        while(!s2.empty()){
            int d=s2.top();
            cout<<d<<"<-";
            s2.pop();
            s1.push(d);
        }
    }
};
int main(){
    TwoStackQueue q;
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
