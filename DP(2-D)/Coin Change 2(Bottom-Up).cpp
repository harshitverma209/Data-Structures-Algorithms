#include<iostream>
#include<vector>
using namespace std;
int findCombinations(vector<int> coins, int M){
    int N=coins.size();
    vector<vector<int>> dp(M+1,vector<int>(N+1,0));
    for(int i=0;i<=N;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            int inc=0,exc=0;
            if(i>=coins[j-1]){
                inc=dp[i-coins[j-1]][j];
            }
            exc=dp[i][j-1];
            dp[i][j]=inc+exc;
        }
    }
    
    // for(auto r:dp){
    //     for(auto c:r){
    //         cout<<c<<"\t";
    //     }
    //     cout<<endl;
    // }
    return dp[M][N];
}
int main(){
    vector<int> coins={1,2,3,4};
    int M=4;
    
    int res=findCombinations(coins,M);

    cout<<res;    
    return 0;
}