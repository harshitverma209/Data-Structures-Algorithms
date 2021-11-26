// C++ program to print left view of Binary Tree
#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to
// create a new Binary Tree Node
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(
                        sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Recursive function to print
// left view of a binary tree.
void leftViewUtil(struct Node *root,
                int level, int *max_level,vector<int> &res)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (*max_level < level)
    {
        // cout << root->data << " ";
        res.push_back(root->data);
        *max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
    leftViewUtil(root->left, level + 1, max_level,res);
    leftViewUtil(root->right, level + 1, max_level,res);
     
}
 
// A wrapper over leftViewUtil()
vector<int> leftView(struct Node *root)
{
    int max_level = 0;
    vector<int> res;
    leftViewUtil(root, 1, &max_level, res);
    return res;
}
 
// Driver Code
int main()
{
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
 
    vector<int> res=leftView(root);
    for(auto e:res){
        cout<<e<<"\t";
    }
 
    return 0;
}