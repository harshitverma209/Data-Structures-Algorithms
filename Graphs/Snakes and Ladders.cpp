#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;
class Node{
    public:
    bool isLadder;
    int data;
    list<pair<int,bool>> nbrs;
    Node(int data){
        this->data = data;
    }
};
class Graph{
    public:
    unordered_map<int,Node*> m;
    int V;
    Graph(int V){
        this->V=V;
        for(int i=1;i<=V;i++){
            m[i] = new Node(i);
        }
    }
    void addEdge(int from,int to, bool isSpecial=false){
        if(isSpecial){
            m[from]->nbrs.clear();
        }
        m[from]->nbrs.push_back(make_pair(to,isSpecial));
    }
    int bfs(int source,int dest){
        queue<int> q;
        bool *visited=new bool[V+1]{0};
        int *distance=new int[V+1];
        q.push(source);
        visited[source]=true;
        distance[source]=0;
        while(!q.empty()){
            int f=q.front();
            // cout<<endl<<f<<": ";
            q.pop();
            for(pair<int,bool> nbrpair:m[f]->nbrs){
                int nbr=nbrpair.first;
                bool isSpecial=nbrpair.second;
                if(!visited[nbr]){
                    q.push(nbr);
                    // cout<<nbr<<",";
                    visited[nbr]=true;
                    int d=1;
                    if(isSpecial){
                        d=0;
                    }
                    distance[nbr]=distance[f]+d;
                    if(nbr==dest){
                        // cout<<"Destination Distance: "<<distance[nbr]<<endl;
                        return distance[nbr];
                    }
                }
            }
        }
        return 0;
    }
};
int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    Graph g(n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=i+6&&j<=n;j++){
            g.addEdge(i,j,false);
        }
    }
    for(pair<int,int> snake:snakes){
        int from = snake.first;
        int to = snake.second;
        g.addEdge(from, to,true);
    }
    for(pair<int,int> ladder:ladders){
        int from = ladder.first;
        int to = ladder.second;
        g.addEdge(from, to,true);
    }
    return g.bfs(1,n);
}

int main(){
    int n=40;
    vector<pair<int,int> > snakes={{17,4},{20,6},{18,29},{25,35}};
    vector<pair<int,int> > ladders={{5,38},{9,27},{18,29},{25,35}};
    cout<<min_dice_throws(n,snakes,ladders);
    
    return 0;
}