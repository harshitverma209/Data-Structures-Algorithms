#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node * left=NULL, * right=NULL;

};
node * buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node * n=new node();
    n->data=d;
    n->left=buildTree();
    n->right=buildTree();
    return n;
}
//Level Order Traversal
void printTree(node * root){
    queue<node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node * n = Q.front();
        if(n==NULL){
            cout<<endl;
            Q.pop();
            if(!Q.empty()){
                Q.push(NULL);
            }
            continue;
        }
        Q.pop();
        cout<<(n->data)<<"\t";
        if(n->left!=NULL){
            Q.push(n->left);
        }
        if(n->right!=NULL){
            Q.push(n->right);
        }
    }
}
//Level Order Build
node * levelOrderBuild(){
    int i;
    cin>>i;
    if(i==-1){
        return NULL;
    }
    node * n = new node();
    n->data =i;
    queue<node *> Q;
    Q.push(n);
    while(!Q.empty()){
        node * f=Q.front();
        int l;
        cin>>l;
        if(l!=-1){
            node * left =new node();
            left->data =l;
            f->left =left;
            Q.push(left);
        }
        int r;
        cin>>r;
        if(r!=-1){
            node * right =new node();
            right->data =r;
            f->right =right;
            Q.push(right);
        }
        Q.pop();
    }
    return n;
}
int height(node * root) {
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}
int treeDiameter(node * root){
    if(root==NULL){
        return 0;
    }
    int d=height(root->left)+height(root->right);
    int d1=treeDiameter(root->left);
    int d2=treeDiameter(root->right);
    d=max(d,max(d1,d2));
    return d;
}
int main(){
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    // node * root=buildTree();
    //1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    node * root =levelOrderBuild();
    printTree(root);
    cout<<treeDiameter(root)<<endl;
    return 0;
}