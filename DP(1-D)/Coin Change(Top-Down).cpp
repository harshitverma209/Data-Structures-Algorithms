#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int coinChange(vector<int> coins, int m, vector<int> &dp){
    //Base Case
    if(m==0){
        return 0;
    }
    //Recursive Case
    int minCount=INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int coin=coins[i];
        if(m>=coin){
            if(dp[m-coin]==-1){
                dp[m-coin]=coinChange(coins,m-coin);
            }
            minCount=min(minCount,dp[m-coin]);
        }
    }
    return minCount+1;
}
int main(){
    vector<int> coins={1,3,7,10};
    int m=15;
    vector<int> dp(m,-1);
    int res=coinChange(coins,m,dp);
    cout<<res;
    return 0;
}