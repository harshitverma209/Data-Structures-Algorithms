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
//In order Traversal
void printInOrder(Node * root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->key<<"\t";
    printInOrder(root->right);
}
//Creating a Min height BSt from a sorted Array
Node *MinHeightBST(int a[],int s, int e){
    if(s>e){
        return NULL;
    }
    int m=(s+e)/2;
    Node * root=new Node(a[m]);
    root->left=MinHeightBST(a,s,m-1);
    root->right=MinHeightBST(a,m+1,e);
    return root;

}
int main() {
    Node * root = NULL;
    int n=9;
    int a[]={1,2,3,4,5,6,7,8,9};
    root=MinHeightBST(a,0,n-1);
    printInOrder(root);
    return 0;
}