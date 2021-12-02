#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int coinChange(vector<int> coins, int m){
    vector<int> dp(m+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=m;i++){
        for(int c:coins){
            if(i>=c){
                dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
    }
    return dp[m];
}
int main(){
    vector<int> coins={1,3,7,10};
    int m=15;
    int res=coinChange(coins,m);
    cout<<res;
    return 0;
}