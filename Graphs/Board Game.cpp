#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define M 3
#define N 4
class Node{
    public:
    char s;
    unordered_map<char, Node*> children;
    string word;
    bool isTerminal;
    Node(char s){
        this->s = s;
        isTerminal = false;
        word="";
    }
};
class Trie{
    public:
    Node *root;
    Trie(){
        root = new Node('\0');
    }
    void insert(string word){
        Node *temp = root;
        for(char c: word){
            if(temp->children.count(c) == 0){
                temp->children[c]=new Node(c);
            }
            temp=temp->children[c];
        }
        temp->isTerminal=true;
        temp->word=word;
    }
};
void dfs(char boggle[M][N],Node *node,int i,int j, bool visited[M][N], unordered_set<string> &output){
    //Base Case
    char ch=boggle[i][j];
    if(node->children.count(ch)==0){
        return;
    }
    //Recursive Case
    visited[i][j]=true;
    node=node->children[ch];
    if(node->isTerminal){
        output.insert(node->word);
    }
    int dx[]={ 0, 1, 1, 1, 0, -1, -1, -1};
    int dy[]={-1,-1, 0, 1, 1,  1,  0, -1};
    for(int k=0; k<8;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0 && nj>=0 && ni<M && nj<N && !visited[ni][nj]){
            dfs(boggle,node,ni,nj,visited,output);
        }
    }
    visited[i][j] = false;
    
}


int main(){
    string words[]={"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};
    char boggle[M][N]={ {'S','E','R','T'},
                        {'U','N','K','S'},
                        {'T','C','A','T'}};
    Trie t;
    for(string word:words){
        t.insert(word);
    }
    unordered_set<string> output;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            bool visited[M][N]={0};
            dfs(boggle,t.root,i,j,visited,output);
        }
    }

    for(auto word:output){
        cout<<word<<endl;
    }
    
    return 0;
}