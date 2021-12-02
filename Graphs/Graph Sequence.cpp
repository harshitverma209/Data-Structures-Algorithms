#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int dfs(vector<vector<int> > grid,int i, int j, vector<vector<int>> &dp,int M, int N){
    //Recursive Case
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    int res=0;
    for(int k=0;k<4;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0 && nj>=0 && ni<M && nj<N && grid[ni][nj]>grid[i][j]){
            if(dp[ni][nj]!=0){
                res=max(res,dp[ni][nj]);
            }else{
                int count=dfs(grid,ni,nj,dp,M,N);
                dp[ni][nj]=count;
                res=max(count,res);
            
            }
        }
    }
    return res+1;
}
int longestPathSequence(vector<vector<int>> grid){
    int M = grid.size();
    int N=grid[0].size();
    vector<vector<int>> dp(M,vector<int>(N,0));
    int res=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(dp[i][j]==0){
                int count=dfs(grid,i,j,dp,M,N);
                if(count>res){
                    res=count;
                }
            }
        }
    }
    return res;
}
int main(){
    vector<vector<int> > grid={ {0,2,4,3,2},
                                {7,6,5,5,1},
                                {8,9,7,18,14},
                                {5,10,11,12,13}
                            };
    cout<<longestPathSequence(grid);
    return 0;
}