#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    Node * left;
    Node * right;
    Node(int key){
        this->key = key;
        left = NULL;
        right = NULL;
    }
};
//BST Creation
Node * insert(Node * root, int e){
    if(root == NULL){
        root = new Node(e);
    }
    if(e>root->key){
        root->right=insert(root->right, e);
    }
    if(e<root->key){
        root->left=insert(root->left, e);
    }
    return root;
}
void printInOrder(Node * root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->key<<"\t";
    printInOrder(root->right);
}
bool isBST(Node *root,Node * l=NULL, Node *r=NULL) {
    if(root==NULL){
        return true;
    }
    if(isBST(root->left,l,root) and isBST(root->right,root,r)){
        if(l!=NULL and l->key>root->key){
            return false;
        }
        if(r!=NULL and r->key<root->key){
            return false;
        }
        return true;
    }
    return false;
}
int main() {
    Node * root = NULL;
    int a[]={1,5,3,6,2,8,9};
    for(int x:a){
        root=insert(root,x);
    }
    printInOrder(root);
    cout<<endl<<isBST(root);
    return 0;
}