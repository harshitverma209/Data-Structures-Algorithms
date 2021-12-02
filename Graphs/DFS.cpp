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
    bool dfsHelper(int node, bool *visited){
        //Base Case
        cout<<node<<"\t";
        visited[node] = true;
        for(int nbr:l[node]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
    }
    void dfs(int source){
        bool *visited=new bool[V]{0};
        dfsHelper(source,visited);
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
    g.dfs(1);
    // g.printAdjacencyList();
    return 0;
}