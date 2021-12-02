#include<iostream>
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
    bool search(string word){
        Node *temp=root;
        for(char ch:word){
            if(temp->m.count(ch)==0){
                return false;
            }
            temp=temp->m[ch];
        }
        return temp->isTerminal;
    }
};
int main(){
    string words[]={"apple","ape","no","news","not","never"};
    Trie t;
    for(auto w:words){
        t.insert(w);
    }
    int q;
    cin>>q;
    while(q--){
        string search_string;
        cin>>search_string;
        if(t.search(search_string)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<endl;
    }
    return 0;
}
/*
4
apple
new
news
ind
*/