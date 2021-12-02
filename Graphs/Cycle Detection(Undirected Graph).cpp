#include<iostream>
#include<list>
#include<queue>
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
    void printAdjacencyList(){
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            for(auto e:l[i]){
                cout<<e<<",";
            }
            cout<<endl;
        }
    }
    bool dfsHelper(int node, bool *visited,bool *s){
        //Base Case
        visited[node] = true;
        s[node]=true;
        for(int nbr:l[node]){
            if(visited[nbr] && s[nbr]){
                return true;
            }
            if(!visited[nbr]){
                if(dfsHelper(nbr,visited,s)){
                    return true;   
                }
            }
        }
        s[node]=false;
        return false;
    }
    bool dfs(int source){
        bool *visited=new bool[V]{0};
        bool *s=new bool[V]{0};
        return dfsHelper(source,visited,s);
    }
};
bool contains_cycle(int v,vector<pair<int,int>> edges){
    Graph g(v);
    for(auto edge:edges){
        g.addEdge(edge.first,edge.second);
    }
    return g.dfs(0);
}
int main(){
    int v=5;
    vector<pair<int,int>> edges={{0,1},{1,2},{2,3},{3,4},{3,0}};
    cout<<contains_cycle(v,edges);
    return 0;
}