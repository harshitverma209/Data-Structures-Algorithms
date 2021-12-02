#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void dfs(vector<vector<int> > grid,int i, int j, vector<vector<int>> &distance,int M, int N){
    //Recursive Case
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0 && nj>=0 && ni<M && nj<N && distance[ni][nj]>distance[i][j]+grid[ni][nj]){
            distance[ni][nj]=distance[i][j]+grid[ni][nj];
            dfs(grid,ni,nj,distance,M,N);
        }
    }

}
int shortest_path(vector<vector<int>> grid){
    int M = grid.size();
    int N=grid[0].size();
    vector<vector<int>> distance(M,vector<int>(N,INT_MAX));
    distance[0][0]=grid[0][0];
    dfs(grid,0,0,distance,M,N);
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