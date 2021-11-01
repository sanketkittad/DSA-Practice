#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
}*head=NULL;
static int count=0;
void create(int a[],int n){
    // Node *p,*temp;
    // head=new Node();
    // head->data=a[0];
    // head->next=head->prev=NULL;
    // p=head;
    // for(int i=1;i<n;++i){
    //     temp=new Node();
    //     temp->data=a[i];
    //     p->next=temp;
        
    // }
    Node *p,*temp;
    head=new Node();
    head->data=a[0];
    head->prev=NULL;
    head->next=NULL;
    temp=head;
    for(int i=1;i<n;++i){
        p=new Node();
        p->data=a[i];
        p->next=temp->next;
        p->prev=temp;
        temp->next=p;
        temp=p;        
    }
    count+=n;
}
void display(Node *head){
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<' ';
        p=p->next;
    }
}
void insert(Node *head,int data){
    Node *temp=head;
    Node *p=new Node();
    p->data=data;
    p->prev=NULL;
    p->next=NULL;
    cout<<"Enter position to enter(0 is before head"<<count+1<<" is end\n";
    int pos;
    cin>>pos;
    if(pos==0){
        p->next=head;
        head=p;
    }
    else if(pos==count+1){
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;
        p->prev=temp;
    }
    else{
        for(int i=0;i<pos-1;++i)temp=temp->next;
        
        p->prev=temp;
        p->next=temp->next;
        temp->next->prev=p;
        temp->next=p;
    }
    ++count;
}
void Delete(Node *head)
{   Node *temp=head;
    cout<<"Enter position to delete: "<<count+1<<" is end\n";
    int pos;
    cin>>pos;
    if(pos==1)
    {
       head=head->next;
       if(head)
       head->prev=NULL;
       delete temp;
    }
    else{
        for(int i=0;i<pos-1;++i)temp=temp->next;
        temp->prev->next=temp->next;
        if(temp->next)
        temp->next->prev=temp->prev;
        delete temp;
    }
    --count;
}
void reverse(Node *head){
    Node *p=head;
    Node *temp=NULL;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL&&p->next==NULL)head=p;
    }

}
int main(){
    int a[]{102,105,107,101,102,109};
    create(a,6);
    
    while(1){
        int choice;
        cin>>choice;
        switch(choice){
        case 1:{
                int data;
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
        case 4:
                reverse(head);
                break;
            }
        default: cout<<"Enter Valid option\n";
        }
    }

    return 0;
}