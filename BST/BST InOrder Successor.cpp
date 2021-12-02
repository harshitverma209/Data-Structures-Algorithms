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
Node * BSTInOrderSuccessor(Node * root, Node * target){
    //If Right Subtree is present, then
    if(target->right!=NULL){
        Node *temp = target->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
    //Otherwise,
    Node * temp=root, *successor = NULL;
    while(temp!=NULL){
        if(temp->key>target->key){
            successor=temp;
            temp=temp->left;
        }else if(temp->key<target->key){
            temp=temp->right;
        }else{
            break;
        }
    }
    return successor;
}
int main() {
    Node * root = NULL;
    int a[]={1,5,3,6,7,2,8,9};
    for(int x:a){
        root=insert(root,x);
    }
    printInOrder(root);
    Node * target=root->right->right;//6
    cout<<BSTInOrderSuccessor(root,target)->key;
    return 0;
}