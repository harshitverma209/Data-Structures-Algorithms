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
bool isPresent(Node *root, int k){
    if(root==NULL){
        return false;
    }
    if(k==root->key){
        return true;
    }
    if(k>root->key){
        return isPresent(root->right,k);
    }
    if(k<root->key){
        return isPresent(root->left,k);
    }
    return false;
}
int main() {
    Node * root = NULL;
    int a[]={1,5,3,6,2,8,9};
    for(int x:a){
        root=insert(root,x);
    }
    // printInOrder(root);
    int e1=8,e2=7;

    cout<<isPresent(root,e1)<<endl;
    cout<<isPresent(root,e2)<<endl;
    return 0;
}