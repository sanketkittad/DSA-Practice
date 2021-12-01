#include <iostream>
#include <queue>
#include<stack>
using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
    Node(int data=0){
        data=this->data;
    }
};
 
class Tree{
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }  // Passing Private Parameter in Constructor
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }
    int Height(Node* p);
    int Height() { return Height(root); }
    void iInorder();
    void iPostorder();
    void iPreorder();
    int count(Node *p);
    int nodeCount(Node *p);
    int leafCount(Node *p);
    int height(Node *p);
};
 
Tree::Tree() {
    root = nullptr;
}
 
Tree::~Tree() {
    // TODO
}
 
void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;
 
    root = new Node();
    cout << "Enter root data: " ;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);
 
    while (! q.empty()){
        p = q.front();
        q.pop();
 
        cout << "Enter left child data of " << p->data << ": " ;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }
 
        cout << "Enter right child data of " << p->data << ": " ;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}
 
void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " ;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}


void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " ;
        Inorder(p->rchild);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " ;
    }
}
 
void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    cout << root->data << ", " ;
    q.emplace(root);
 
    while (! q.empty()){
        p = q.front();
        q.pop();
 
        if (p->lchild){
            cout << p->lchild->data << ", " ;
            q.emplace(p->lchild);
        }
 
        if (p->rchild){
            cout << p->rchild->data << ", " ;
            q.emplace(p->rchild);
        }
    }
}
 
void Tree::iPreorder(){
    stack<Node*> st;
    Node *t=root;
    while(t!=NULL || !st.empty()){
        if(t!=NULL)
        {
            cout<<t->data<<'\n';
            st.push(t);
            t=t->lchild;
        }
        else{
            t=st.top();
            st.pop();
            t=t->rchild;
        }
    }
}

void Tree::iInorder(){
    stack<Node *> st;
    Node *t=root;
    while(t!=NULL || !st.empty()){
        if(t!=NULL)
        {
            st.push(t);
            t=t->lchild;
        }
        else{
            t=st.top();
            st.pop();
            cout<<t->data<<'\n';
            t=t->rchild;
        }
    }  
}
void Tree::iPostorder(){
    stack<long int> stk;
    long int temp;
    Node *p=root;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.emplace((long int)p);
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}
 
int searchIn(int inOrder[],int start,int end,int data){
    for(int i=start;i<=end;++i){
        if(inOrder[i]==data)
            return i;
    }
    return -1;
}

int Tree::count(Node *p){
    if(p)
        return count(p->lchild)+count(p->rchild+1);
    else return 0;
}
int Tree::height(Node *p){
    int x=0,y=0;
    if(p==0){
        return 0;
    }
    else{
        x=height(p->lchild);
        y=height(p->rchild);
        return x+y+1;
    }
}
Node *generate(int *inOrder,int *preOrder,int start,int end){
    static int start1=0;
    if(start>end)return NULL;
    Node *node=new Node(preOrder[start1++]);
    if(start==end)return node;
    int split=searchIn(inOrder,start,end,node->data);
    node->lchild=generate(inOrder,preOrder,start,split-1);
    node->rchild=generate(inOrder,preOrder,split+1,end);
    return node;
}
int Tree::nodeCount(Node *p){
    int x=0,y=0;
    if(p==0){
        return 0;
    }
    else{
        x=height(p->lchild);
        y=height(p->rchild);
        return x+y+1;
    }
}
int Tree::leafCount(Node *p){
    if(p==NULL)
        return 0;
    if(!p->lchild && !p->rchild)
        return count(p->lchild)+count(p->rchild)+1;
    return count(p->lchild)+count(p->rchild);
}
int main() {
    Tree bt;
    bt.CreateTree();
    while(1){
        cout<<"1. Preorder\n2. Iterative Preorder\n3. Postorder\n4. Iterative Postorder\n5. Inorder\n6. Iterative Inorder\n7. Level Order\n8. Generate Tree\n9. Exit\nEnter Option: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                bt.Preorder();
                break;
            case 2:
                bt.iPreorder();
                break;
            case 3:
                bt.Postorder();
                break;
            case 4:
                bt.iPostorder();
                break;
            case 5:
                bt.Inorder();
                break;
            case 6:
                bt.iInorder();
            case 7:
                bt.Levelorder();
                break;
            case 8:
                bt.g
        }
    }
    return 0;
}