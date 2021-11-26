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
class HDPair{
    public:
    int height;
    int diameter;
    HDPair(int height, int diameter){
        this->height=height;
        this->diameter=diameter;
    }
};
class BHPair{
    public:
    bool balanced;
    int height;
    BHPair(bool balanced, int height){
        this->balanced=balanced;
        this->height=height;
    }
};
BHPair heightBalancedTree(node * root){
    //Base Case
    if(root==NULL){
        return BHPair(true,0);
    }
    //Recursive Case
    BHPair bhLeft=heightBalancedTree(root->left);
    BHPair bhRight=heightBalancedTree(root->right);
    if(!bhLeft.balanced || !bhRight.balanced || abs(bhLeft.height-bhRight.height)>1){
        return BHPair(false,1+max(bhLeft.height,bhRight.height));
    }
    return BHPair(true, 1+max(bhLeft.height,bhRight.height));
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
HDPair optimizedTreeDiameter(node * root){
    if(root==NULL){
        return HDPair(0,0);
    }
    HDPair hd1=optimizedTreeDiameter(root->left);
    HDPair hd2=optimizedTreeDiameter(root->right);
    int d=hd1.height+hd2.height;
    int h=max(hd1.height,hd2.height)+1;
    d=max(d,max(hd1.diameter,hd2.diameter));
    return HDPair(h,d);
}
int replaceWithDescendantSum(node *root){
    //Base Case
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;    
    }
    //Recursive Case
    int data=root->data;
    root->data=replaceWithDescendantSum(root->left)+replaceWithDescendantSum(root->right);
    return data+root->data;
}
class IncExcPair{
    public:
    int inc;
    int exc;
    IncExcPair(int inc, int exc){
        this->inc=inc; this->exc=exc;
    }
};
//Max Subset Sum
IncExcPair maxSubsetSum(node * root){
    //Base Case
    if(root==NULL){
        return IncExcPair(0,0);
    }
    //Recursive Case
    node *left = root->left;
    node *right = root->right;
    int data=root->data;
    IncExcPair L=maxSubsetSum(left),R=maxSubsetSum(right);
    int inc=(L.exc+R.exc+data);
    int exc=max(L.exc,L.inc)+max(R.exc,R.inc);
    return IncExcPair(inc,exc);
    //return max(currSum+data,maxSubsetSum(root->left,currSum,sum)+maxSubsetSum(root->right,currSum,sum));
}
//Print At Level K
void printAtLevelK(node * root, int K){
    if(root==NULL){
        return;
    }
    if(K==0){
        cout<<root->data<<"\t";
        return;
    }
    printAtLevelK(root->left,K-1);
    printAtLevelK(root->right,K-1);
}
int nodesAtDistanceK(node * root, node * target, int K){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printAtLevelK(root,K);
        return 0;
    }
    int leftSubtreeDistance=nodesAtDistanceK(root->left,target,K);
    int rightSubtreeDistance=nodesAtDistanceK(root->right,target,K);
    if(leftSubtreeDistance!=-1){
        if(K==leftSubtreeDistance+1){
            cout<<root->data<<"\t";
        }
        else{
            printAtLevelK(root->right,K-leftSubtreeDistance-2);
        }
        return leftSubtreeDistance+1;
    }
    if(rightSubtreeDistance!=-1){
        if(K==rightSubtreeDistance+1){
            cout<<root->data<<"\t";
        }
        else{
            printAtLevelK(root->left,K-rightSubtreeDistance-2);
        }
        return rightSubtreeDistance+1;
    }
    return -1;
}
int main(){
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    // node * root=buildTree();
    //1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    node * root =levelOrderBuild();
    printTree(root);
    cout<<endl;
    cout<<optimizedTreeDiameter(root).diameter<<endl;
    // replaceWithDescendantSum(root);
    printTree(root);
    cout<<endl;
    cout<<heightBalancedTree(root).balanced<<endl;
    IncExcPair R=maxSubsetSum(root);
    cout<<max(R.inc,R.exc)<<endl;
    int K=3;
    printAtLevelK(root,K);
    cout<<endl;
    nodesAtDistanceK(root,)
    return 0;
}