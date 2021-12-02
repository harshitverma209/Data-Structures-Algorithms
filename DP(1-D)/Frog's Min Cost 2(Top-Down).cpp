#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minCost(vector<int> stones, int i, int JUMP, int N, vector<int> &dp){
    //Base Case
    if(i==N-1){
        return 0;
    }
    if(i>=N){
        return INT_MAX;
    }
    //Recursive Case
    if(dp[i]==INT_MAX){
        for(int k=1;k<=JUMP && i+k<N;k++){
            dp[i] = min(dp[i],minCost(stones,i+k,JUMP,N,dp)+abs(stones[i]-stones[i+k]));
        }
    }
    return dp[i];
}
int main(){
    vector<int> stones={10,30,40,20};
    int K=2;
    int N=stones.size();
    vector<int> dp(N,INT_MAX);
    int res=minCost(stones,0,K,N,dp);
    cout<<res;
    return 0;
}