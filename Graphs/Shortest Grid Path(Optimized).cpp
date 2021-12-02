#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;
class Node{
    public:
    int x,y,dist;
    Node(int i,int j, int dist){
        this->x=i;
        this->y=j;
        this->dist=dist;
    }
};
class Compare{
    public:
    bool operator()(const Node &a, const Node &b){
        return a.dist<=b.dist;
    }
};
int shortest_path(vector<vector<int>> grid){
    int i=0,j=0;
    int M = grid.size();
    int N=grid[0].size();
    set<Node,Compare> s;
    vector<vector<int>> distance(M,vector<int>(N,INT_MAX));
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    distance[0][0]=grid[0][0];
    s.insert(Node(0,0,distance[0][0]));
    while(!s.empty()){
        auto it = s.begin();
        int x=it->x;
        int y=it->y;
        int dist=it->dist;
        s.erase(it);
        for(int k=0;k<4;k++){
            int ni=x+dx[k];
            int nj=y+dy[k];
            if(ni>=0 && nj>=0 && ni<M && nj<N && distance[ni][nj]>dist+grid[ni][nj]){
                Node temp(ni,nj,distance[ni][nj]);
                if(s.find(temp)!=s.end()){
                    s.erase(s.find(temp));
                }
                distance[ni][nj]=dist+grid[ni][nj];
                s.insert(Node(ni,nj,distance[ni][nj]));
            }
            
        }
    }
    return distance[M-1][N-1];
}
int main(){
    vector<vector<int> > grid={ {31,    100,   65,  12,     18 },
                                {10,    13,    47,  157,    6  },
                                {100,   113,   174, 11,     33 },
                                {88,    124,    41, 20,     140},
                                {99,    32,    111, 41,     20 }
                            };
    cout<<shortest_path(grid);
    return 0;
}