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
    int dfsHelper(int node, vector<bool> &visited, int count){
        //Base Case
        cout<<node<<"\t";
        visited[node] = true;
        for(int nbr:l[node]){
            if(!visited[nbr]){
                count++;
                count=dfsHelper(nbr,visited,count);
            }
        }
        return count;
    }

};
int count_pairs(int N, vector<pair<int,int> > astronauts){
    //complete this method
    Graph g(N);
    for(auto p:astronauts){
        g.addEdge(p.first,p.second);
    }
    vector<bool> visited(N,false);
    vector<int> afec;     //Astronauts from each country
    for(int i=0;i<N;i++){
        if(!visited[i]){
            int c=g.dfsHelper(i,visited,0);
            afec.push_back(c);
        }
    }
    int pairs=0;
    for(int i=0;i<afec.size();i++){
        for(int j=0;j<afec.size();j++){
            pairs+=afec[i]*afec[j];
        }
    }
    
    return pairs;
    
    
}
int main(){
    int N=4;
    vector<pair<int,int> > astronauts={{1,2},{2,3}};
    
    return 0;
}