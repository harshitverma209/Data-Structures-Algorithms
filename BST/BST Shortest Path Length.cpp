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
Node* lca(Node*root, int a, int b){
    //Complete this function and return address of the node
    while(root!=NULL){
        int k=root->key;
        if(k>a and k>b){
            root=root->left;
        }else if(k<a and k<b){
            root=root->right;
        }else{
            break;
        }
    }
    return root;
}
int shortestDist(Node * root,int a,int b){
    //Complete this method
    Node * ancestor=lca(root,a,b);
    int aDis=0,bDis=0;
    Node * aReach=ancestor;
    Node * bReach=ancestor;
    while(aReach->key!=a){
        if(aReach->key>a){
            aReach=aReach->left;
        }else{
            aReach=aReach->right;
        }
        aDis++;
    }
    while(bReach->key!=b){
        if(bReach->key>b){
            bReach=bReach->left;
        }else{
            bReach=bReach->right;
        }
        bDis++;
    }
    return aDis+bDis;
}
int main() {
    Node * root = NULL;
    int a[]={1,5,3,6,2,8,9};
    for(int x:a){
        root=insert(root,x);
    }
    printInOrder(root);

    cout<<endl<<shortestDist(root,6,8);
    return 0;
}
