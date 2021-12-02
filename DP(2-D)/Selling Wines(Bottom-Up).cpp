#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> wines){
    int N=wines.size();
    vector<vector<int>> dp(N+1,vector<int>(N+1,0));
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<N;j++){
            if(i<=j){
                int y=N-(j-i);
                dp[i][j]=max(dp[i+1][j]+wines[i]*y,dp[i][j-1]+wines[j]*y);
            }
        }
    }
    return dp[0][N-1];
}
int main(){
    vector<int> wines={2,3,5,1,4};

    int res=maxProfit(wines);
    cout<<res<<endl;
    return 0;
}