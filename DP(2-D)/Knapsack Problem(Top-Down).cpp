#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int> weights,vector<int> prices, int N, int W, vector<vector<int>> &dp){
    //Base Case
    if(N<0 or W<=0){
        return 0;
    }
    //Recursive Case
    if(dp[N][W]==-1){
        if(weights[N]<=W){
            return dp[N][W]=max(knapsack(weights, prices,N-1,W,dp),knapsack(weights, prices,N-1,W-weights[N],dp)+prices[N]);
        }
    }
    return dp[N][W]=knapsack(weights, prices,N-1,W,dp);
}
int main(){
    int W=11;
    vector<int> weights={2,7,3,4};
    vector<int> prices={5,20,20,10};
    int N=weights.size();
    vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
    int res=knapsack(weights, prices,N-1,W,dp);
    // for(auto r:dp){
    //     for(auto c:r){
    //         cout<<c<<"\t";
    //     }
    //     cout<<endl;
    // }
    cout<<res;
    return 0;
}