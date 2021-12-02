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
int main(){
    string suffixes[]={"ello","llo","oll","ell"};
    Trie t;
    t.insert("hello");
    for(int i=0;i<4;i++){
        string search_string=suffixes[i];
        if(t.search(search_string)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<endl;
    }
    return 0;
}
