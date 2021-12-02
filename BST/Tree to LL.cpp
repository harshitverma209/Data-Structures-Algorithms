#include<iostream>
#include<climits>
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
pair<Node *, Node *> flatten(Node * root){
    Node * head=root;
    Node * tail=root;
    if(root->left){
        pair<Node *, Node *> HLTL=flatten(root->left);
        Node * HL=HLTL.first;
        Node * TL=HLTL.second;
        TL->right=root;
        head=HL;
    }
    if(root->right){
        pair<Node *, Node *> HRTR=flatten(root->right);
        Node * HR=HRTR.first;
        Node * TR=HRTR.second;
        root->right=HR;
        tail=TR;
    }
    return make_pair(head,tail);
}
void printLL(Node * head){
    while(head!=NULL){
        cout<<head->key<<"\t";
        head=head->right;
    }
}
int main() {
    Node * root = NULL;
    int a[]={8,3,10,1,6,14,4,7,13};
    for(int x:a){
        root=insert(root,x);
    }
    // printInOrder(root);
    // int e1=8,e2=17;
    // cout<<closestInBST(root,e2);
    root=flatten(root).first;
    printLL(root);
    return 0;
}