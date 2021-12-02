#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minCost(vector<int> stones,int K){
    int N=stones.size();
    vector<int> dp(N,INT_MAX);
    dp[N-1]=0;
    for(int i=N-2;i>=0;i--){
        for(int j=1;j<=K && i+j<N;j++){
            dp[i]=min(dp[i],dp[i+j]+abs(stones[i]-stones[i+j]));
        }
    }
    return dp[0];
}
int main(){
    vector<int> stones={10,30,40,20};
    int K=2;
    int N=stones.size();
    int res=minCost(stones,K);
    cout<<res;
    return 0;
}