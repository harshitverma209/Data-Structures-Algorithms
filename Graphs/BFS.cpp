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
    void addEdge(int i, int j, bool undir=true){
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
    void bfs(int source){
        queue<int> q;
        bool *visited=new bool[V]{0};
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int f=q.front();
            cout<<f<<endl;
            q.pop();
            for(int nbr:l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
};
int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.bfs(1);
    // g.printAdjacencyList();
    return 0;
}