#include<iostream>
#include<stack>
using namespace std;
class Node{
    int data;
    Node *lchild,*rchild;
    friend class BST;
    public:
    Node(int data=0){
        this->data=data;
        this->lchild=NULL;
        this->rchild=NULL;
    }
};
Node *root;
class BST{
    
    public:
    BST(){
        root=NULL;
    }
    void insert(int data){
        Node *p,*t=root,*r;
        if(root==NULL){
            root=new Node(data);
            return;
        }
        while(t!=NULL){
            r=t;
            if(t->data>data)
                t=t->lchild;
            else if(t->data<data)
                t=t->rchild;
            else
                return;
        }
        p=new Node(data);
        if(r->data>data)
            r->lchild=p;
        else if(r->data<data)
            r->rchild=p;
        else
                return;
    }
     void inorder(Node *p=root){
         if(p!=NULL){
             inorder(p->lchild);
             cout<<p->data<<' ';
             inorder(p->rchild);
         }
     }
     Node *search(int data,Node *p=root){
         while(p!=NULL){
             if(data==p->data)
                return p;
            else if(data<p->data)
                p=p->lchild;
            else
                p=p->rchild;
         }
         return NULL;
    }
    int height(Node *p=root){
        int x,y;
        if(p==NULL)return 0;
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)return x+1;
        else return y+1;
    }
    Node *inPre(Node *p=root){
        while(p!=NULL && p->rchild!=NULL){
            p=p->rchild;
        }
        return p;
    }
    Node *inSucc(Node *p=root){
        while(p!=NULL && p->lchild!=NULL){
            p=p->lchild;
        }
        return p;
    }
    Node *Delete(int data,Node *p=root){
        Node *q;
        if(p==NULL)return NULL;
        if(p->lchild==NULL && p->rchild==NULL){
            if(p==root)root=NULL;
            delete p;
            return NULL;
        }
        if(data<p->data){
            p->lchild=Delete(data,p->lchild);
        }
        else if(data>p->data){
            p->rchild=Delete(data,p->rchild);
        }
        else{
            if(height(p->lchild)>height(p->rchild)){
                q=inPre(p->lchild);
                p->data=q->data;
                p->lchild=Delete(q->data,p->lchild);
            }
            else{
                q=inSucc(p->rchild);
                p->data=q->data;
                p->rchild=Delete(q->data,p->rchild);
            }
        }
        return p;
    }
    void createBST(int *pre,int n){
        int i=0;
        root=new Node(pre[i++]);
        Node *t;
        Node *p=root;
        stack<Node*> st;
        while(i<n){
            if(pre[i]<p->data){
                t=new Node(pre[i++]);
                p->lchild=t;
                st.push(p);
                p=t;
            }
            else{
                if(pre[i]>p->data && pre[i]<st.empty()?32767:st.top()->data){
                    t=new Node(pre[i++]);
                    p->rchild=t;
                    p=t;
                }
                else{
                    p=st.top();
                    st.pop();
                }
            }
        }
    }
};
int main(){
    BST bt;
    bt.insert(6);
    bt.insert(1);
    bt.insert(11);
    bt.insert(8);
    bt.insert(3);
    bt.insert(111);
    bt.insert(89);
    bt.insert(43);
    bt.insert(100);
    bt.insert(24);
    bt.insert(17);
    bt.inorder();
    bt.Delete(111);
    bt.inorder();
    return 0;
}