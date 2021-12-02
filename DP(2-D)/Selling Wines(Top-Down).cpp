#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> wines, int L, int R, int year, vector<vector<int>> &dp ){
    if(L>R){
        return 0;
    }
    if(dp[L][R]==0){
        dp[L][R]=max(maxProfit(wines,L+1,R,year+1)+year*wines[L],maxProfit(wines,L,R-1,year+1)+year*wines[R]);
    }
    return dp[L][R];
}
int main(){
    vector<int> wines={2,3,5,1,4};
    int N=wines.size();
    vector<vector<int>> dp(N+1,vector<int>(N+1,0));
    int res=maxProfit(wines,0,N-1,1,dp);
    cout<<res<<endl;
    return 0;
}