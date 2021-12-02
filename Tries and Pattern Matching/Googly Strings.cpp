#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    char data;
    unordered_map<char,Node*> m;
    bool isTerminal;
    Node(char d){
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
    void insert(string word){
        Node *temp=root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                Node *n=new Node(ch);
                temp->m[ch]=n;
            }
            temp=temp->m[ch];
        }
        temp->isTerminal=true;
    }
};
int countMaxInstances(Node *root,string word, int i){
    //Base Case
    if(i==word.length()){
        return 0;
    }
    //Recursive Case
    Node * orig_root=root;
    int maxInstances=-1;
    for(int j=i;j<word.length();j++){
        char ch=word[j];
        if(root->m.count(ch)==0){
            break;
        }
            root=root->m[ch];
        if(root->isTerminal){
            //One Instance Found
            int rem=countMaxInstances(orig_root,word,j+1);
            if(rem!=-1){
                maxInstances=max(maxInstances,rem+1);
            }
        }
    }
    return maxInstances;
}
vector<string> googlyStrings(vector<string> words){
    vector<string> res;
    Trie t;
    for(auto w:words){
        t.insert(w);
    }
    for(auto w:words){
        int count=countMaxInstances(t.root,w,0);
        if(count>1){
            res.push_back(w);
        }
    }
    return res;
}
int main(){
    vector<string> words={"goo","gle","google","le","googly","ly","g","googoole"};
    vector<string> res=googlyStrings(words);
    for(auto s:res){
        cout<<s<<endl;
    }
    return 0;
}