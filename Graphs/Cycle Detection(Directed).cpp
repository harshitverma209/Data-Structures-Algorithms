#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;
class Graph{
    public:
    int V;
    list<int> *l;
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }
    void addEdge(int i, int j, bool undir=false){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
};
bool contains_cycle(int v,vector<pair<int,int>> edges){
    Graph g(v);
    for(pair<int,int> edge:edges){
        int from = edge.first;
        int to = edge.second;
        g.addEdge(from,to);
    }
    bool s[v];
    int source=0;
    queue<int> q;
    bool *visited=new bool[v]{0};
    q.push(source);
    visited[source]=true;
    bool s[v]={0};
    s[source]=true;
    while(!q.empty()){
        int f=q.front();
        
        // cout<<f<<endl;
        q.pop();
        for(int nbr:g.l[f]){
            if(visited[nbr] && nbr!=parent[f]){
                return true;
            }
            if(!visited[nbr]){
                parent[nbr]=f;
                q.push(nbr);
                visited[nbr]=true;
            }
        }
    }
    return false;

}
int main(){
    int v=3;
    vector<pair<int,int>> edges={{1,2},{0,1},{2,0}};
    cout<<contains_cycle(v,edges);
    return 0;
}