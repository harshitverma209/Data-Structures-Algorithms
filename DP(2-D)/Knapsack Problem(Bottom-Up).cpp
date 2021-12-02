#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int> weights,vector<int> prices,int W){
    int N=weights.size();
    vector<vector<int>> dp(N+1,vector<int>(W+1,0));
    for(int i=0;i<N;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<W;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=W;j++){
            if(weights[i]<=j){
                dp[i][j]=max(dp[i-1][j-weights[i]]+prices[i],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
        // for(auto r:dp){
        // for(auto c:r){
        //     cout<<c<<"\t";
        // }
        // cout<<endl;
    }
    return dp[N][W];
}
int main(){
    int W=11;
    vector<int> weights={2,7,3,4};
    vector<int> prices={5,20,20,10};

    int res=knapsack(weights, prices,W);
    // for(auto r:dp){
    //     for(auto c:r){
    //         cout<<c<<"\t";
    //     }
    //     cout<<endl;
    // }
    cout<<res;
    return 0;
}