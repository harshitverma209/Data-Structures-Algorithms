#include<iostream>
#include<vector>
using namespace std;
int dfs(vector<vector<int> > matrix, vector<vector<bool>> &visited,int i, int j, int M, int N){
    //Recursive Case
    visited[i][j]=true;
    int current_size=1;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0 && nj>=0 && ni<M && nj<N && !visited[ni][nj] && matrix[ni][nj]==1){
            current_size+=dfs(matrix,visited,ni,nj,M,N);
        }
    }
    return current_size;
}
int largest_island(vector<vector<int>> matrix) {
    int M=matrix.size();
    int N=matrix[0].size();
    vector<vector<bool>> visited(M,vector<bool>(N,false));
    int largest=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j] && matrix[i][j]==1){
                int size=dfs(matrix,visited,i,j,M,N);
                if(size>largest){
                    largest=size;
                }
            }
        }
    }
    return largest;
}
int main(){
     vector<vector<int> > grid={{1,0,0,1,0},
                                {1,0,1,0,0},
                                {1,1,1,0,0},
                                {1,0,1,1,1},
                                {1,0,1,1,0}
                            };
    cout<<largest_island(grid);
    return 0;
}