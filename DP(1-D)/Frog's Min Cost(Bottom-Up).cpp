#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minCost(vector<int> stones){
    int N=stones.size();
    vector<int> dp(N,INT_MAX);
    dp[N-1]=0;
    for(int i=N-2;i>=0;i--){
        for(int k=1;k<=2 && i+k<N;k++){
            dp[i]=min(dp[i],dp[i+k]+abs(stones[i]-stones[i+k]));
        }
    }
    return dp[0];
}
int main(){
    vector<int> stones={10,30,40,20};
    int N=stones.size();
    int res=minCost(stones);
    cout<<res;
    return 0;
}