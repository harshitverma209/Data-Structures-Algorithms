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
    void insert_helper(string word){
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
    void insert(string word){
        for(int i=0;word[i]!='\0';i++){
            insert_helper(word.substr(i));
        }
    }
};

void searchHelper(Trie t, string document, int i, unordered_map<string,bool> &m){
    Node *temp=t.root;
    for(int j=i;j<=document.length();j++){
        char ch=document[j];
        if(temp->m.count(ch)==0){
            return;
        }
        temp=temp->m[ch];
        if(temp->isTerminal){
            string s=document.substr(i,j-i+1);
            m[s]=true;
        }
    }
}
void documentSearch(string document,vector<string> words){
    Trie t;
    for(string w:words){
        t.insert(w);
    }
    unordered_map<string,bool> m;
    for(int i=0;i<document.length();i++){
        searchHelper(t,document,i,m);
    }
    for(auto w:words){
        if(m[w]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}
int main(){
    vector<string> words={"cool","are","ill","hat","will","the"};
    string document="i am cool are you well we will see about that will we not";
    documentSearch(document, words);
    
    
    
    return 0;
}
