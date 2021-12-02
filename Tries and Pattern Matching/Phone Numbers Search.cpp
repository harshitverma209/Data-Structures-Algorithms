#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

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

void searchHelper(Node *root, string number, int i, string w, unordered_set<string> &m){
    //Base Case
    if(root->isTerminal){
        // cout<<"Terminal"<<endl;
        m.insert(w);
        // return;
    }
    if(i==number.length()){
        return;
    }

    //Recursive Case
    int digit=number[i]-'0';
    string chars=keypad[digit];
    // cout<<endl<<"chars:"<<w<<endl;

    for(char ch:chars){
        if(root->m.count(ch)!=0){
            // cout<<ch;
            searchHelper(root->m[ch],number,i+1,w+ch,m);
        }
    }
}

vector<string> numberSearch(string number,vector<string> words){
    Trie t;
    for(string w:words){
        t.insert_helper(w);
    }
    // cout<<"Prateek FOund:"<<t.search("prateek");
    unordered_set<string> m;
    for(int i=0;i<number.length();i++){
        searchHelper(t.root,number,i,"",m);
    }
    vector<string> res;
    for(auto w:m){
        res.push_back(w);
    }
    return res;
}
int main(){
    vector<string> words={"prat","prateek","codingminutes","code","prat335","teek"};
    string number="7728335";
    vector<string> res=numberSearch(number, words);
    for(auto w:res){
        cout<<w<<"\t";
    }
    
    return 0;
}
