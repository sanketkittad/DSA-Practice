#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
}*head=NULL;
static int count=0;
void insert(Node **head,int data){
    Node *p=new Node();
    p->data=data;
    if(*head==NULL){
        *head=p;
        (*head)->next=NULL;
        ++count;
    }
    else{
        cout<<"Enter position to enter the element(0 is at the beginning, "<<count<<" at the end): ";
        int pos;
        cin>>pos;
        if(pos==0){
            p->next=*head;
            *head=p;
            ++count;
        }
        else if(pos==count){
            Node *temp=*head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=p;
            p->next=NULL;
            ++count;
        }
        else{
            Node *temp=*head;
            for(int i=0;i<pos-1;++i){
                temp=temp->next;
            }
            p->next=temp->next;
            temp->next=p;
            ++count;
        }
    }
}
int search(Node **head,int s){
    Node *temp=*head;
    int pos=1;
    while(temp!=NULL){
        if(s==temp->data){
            return pos;
        }
        temp=temp->next;
        ++pos;
    }
    return -1;
}
void display(Node *head){
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<' '; 
        p=p->next;
        }
}
void Delete(Node **head){
    Node *temp=*head;
    int index;
    cout<<"Enter index to be deleted(1 is the first,"<<count<<" is the last.): ";
    cin>>index;
    if(index==1){
        *head=temp->next;
        temp->next=NULL;
    }
    else if(index==count){
        Node *q=NULL;
        while(temp->next!=NULL){
            q=temp;
            temp=temp->next;
        }
        q->next=NULL;
        delete temp;
    }
    else{
        Node *q=NULL;
        for(int i=1;i<index;++i){
            q=temp;
            temp=temp->next;
        }
        q->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
}
void deleteDuplicate(Node **head){
    Node *q=*head,*p=q->next;
    while(p!=NULL){
        if(p->data!=q->data){
            q=p;
            p=p->next;
        }
        else{
            Node *temp=p;
            q->next=p->next;
            delete p;
            p=q->next;

        }
    }
}
Node *reverse(Node **head){
    Node *p=*head;
    Node *q=NULL;
    Node *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *head=q;
    return *head;
}
void concatenate(Node **head1,Node **head2){
    Node *p=*head1;
    Node *q=*head2;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}
void merge(Node **head1,Node **head2){
    Node *last,*p=*head1,*q=*head2;
    if(p->data<q->data){
        last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
        last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p!=NULL && q!=NULL){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL){
        last->next=p;
    }
    else last->next=q;
}
void rReverse(Node *q,Node *p){
    if(p!=NULL){
        rReverse(p,p->next);
        p->next=q;
    }
    else
        head=q;
}
bool checkloop(Node **head){
    Node *p=*head,*q=*head;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p&&q&&p!=q);
    return p==q;
}
int main(){
    while(1){
        cout<<"\n1. Enter node\n2. Display\n3. Search\n4. Delete\n5. Reverse\n6. Recursive reverse\n7. Check Loop\n8. Exit\n";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:{
                int data;
                cin>>data;
                insert(&head,data);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                int s;
                cout<<"Enter Data to be searched: ";
                cin>>s;
                cout<<search(&head,s);
                break;
            }
            case 4:{
                Delete(&head);
                break;
            }
            case 5:{
                Node *rev=reverse(&head);
                display(rev);
                break;
            }
            case 6:{
                Node *q=NULL;
                rReverse(q,head);
                display(head);
                break;
            }
            case 7:{
                if(checkloop(&head))
                    cout<<"No loop\n";
            else
                cout<<"Loop\n";
                break;
            }
            case 8:{
                exit(0);
            }
            
        }
    }
    return 0;
}