#include<iostream>
#include<vector>
using namespace std;
int findCombinations(vector<int> coins, int M, int N, vector<vector<int>> &dp){
    if((N<0 and M>0) or M<0){
        return 0;
    }
    if(M==0){
        return 1;
    }
    if(dp[M][N]!=0){
        return dp[M][N];
    }
    int inc=findCombinations(coins, M-coins[N], N, dp);
    int exc=findCombinations(coins,M,N-1,dp);
    dp[M][N]=inc+exc;
    
    return dp[M][N];
}
int main(){
    vector<int> coins={1,2,3,4};
    int M=4;
    int N=coins.size();
    vector<vector<int>> dp(M+1,vector<int>(N+1,0));
    int res=findCombinations(coins,M,N-1,dp);
    for(auto r:dp){
        for(auto c:r){
            cout<<c<<"\t";
        }
        cout<<endl;
    }
    cout<<res;    
    return 0;
}