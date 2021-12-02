#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    unordered_map<int,Node*> m;
    bool isTerminal;
    Node(int d){
        data=d;
        isTerminal=false;
    }
};
class Trie{
    public:
    Node *root;
    Trie(){
        root = new Node('\0');
    }
    void insert(int n){
        Node *temp=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(temp->m.count(bit)==0){
                temp->m[bit]=new Node(bit);
            }
            temp=temp->m[bit];
        }
        temp->isTerminal=true;
    }
};
int max_xor_helper(int value,Trie t){
    int current_ans=0;
    Node *temp=t.root;
    for(int j=31;j>=0;j--){
        int bit=(value>>j)&1;
        int opp_bit=abs(bit-1);
        if(temp->m.count(opp_bit)!=0){
            temp=temp->m[opp_bit];
            current_ans+=(1<<j);
        }else{
            temp=temp->m[bit];
        }
    }
    return current_ans;
}
int max_xor(int *input,int n){
    int mx=0;
    Trie t;
    for(int i=0;i<n;i++){
        int value=input[i];
        t.insert(value);
        int current_xor=max_xor_helper(value,t);
        mx=max(mx,current_xor);
    }
    return mx;
}
int main(){
    int arr[]={3,10,5,25,9,2};
    int mx=max_xor(arr,6);
    cout<<mx<<endl;
    return 0;
}
