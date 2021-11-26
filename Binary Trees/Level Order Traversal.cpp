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
        }
        cout<<(n->data)<<"\t";
        if(n->left!=NULL){
            Q.push(n->left);
        }
        if(n->right!=NULL){
            Q.push(n->right);
        }
        Q.pop();
    }
}
int main(){
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    node * root=buildTree();
    printTree(root);
    return 0;
}