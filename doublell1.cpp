#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
}*head=NULL;
static int count=0;

void create(int a[],int n){
    Node *p,*temp;
    head=new Node();
    head->data=a[0];
    head->next=head->prev=NULL;
    temp=head;
    for(int i=1;i<n;++i){
        p=new Node();
        p->data=a[i];
        p->next=temp->next;
        p->prev=temp;
        temp->next=p;
        temp=p;
    }
    count+=6;
}
void display(Node *p){
    while(p!=NULL)
        {
            cout<<p->data<<' ';
            p=p->next;
        }
}
void insert(Node *p,int data){
    Node *temp=new Node();
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    cout<<"Enter position to enter(0 is beginning, "<<count<<" is the end: ";
    int pos;
    cin>>pos;
    if(pos==0){
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else{
        for(int i=0;i<pos-1;++i){
            p=p->next;
        }
        temp->prev=p;
        temp->next=p->next;
        if(p->next)p->next->prev=temp;
        p->next=temp;
    }
    ++count;
}
void Delete(Node *p){
    cout<<"Enter position to be deleted("<<count<<" is last)"<<": ";
    int pos;
    cin>>pos;
    if(pos==1){
        p->next->prev=NULL;
        head=p->next;
        if(head)
        head->prev=NULL;
        delete p;
    }    
    else{
        for(int i=0;i<pos-1;++i)p=p->next;
        p->prev->next=p->next;
        if(p->next )
        p->next->prev=p->prev;
        p->next=NULL;
        p->prev=NULL;
        delete p;
    }
}
void reverse(Node *p){
    Node *temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL&&p->next==NULL) head=p;        
    }
}
int main(){
    int a[]{100,101,102,111,123,135};
    create(a,6);
    while(1){
        int opt;
        cin>>opt;
        switch(opt){
            case 1:{
                int data;
                cout<<"Enter data: ";
                cin>>data;
                insert(head,data);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                Delete(head);
                break;
            }
            case 4:{
                reverse(head);
                break;
            }
            default: cout<<"Enter valid.\n";
        }
    }
    return 0;
}