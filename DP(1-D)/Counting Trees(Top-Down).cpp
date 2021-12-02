#include<iostream>
#include<vector>
using namespace std;
int countTrees(int N,vector<int> &dp){
    //Base Case
    if(N==0 || N==1){
        return 1;
    }
    if(dp[N]==0){
        for(int i=1; i<=N; i++){
            dp[N]+=countTrees(i-1,dp)*countTrees(N-i,dp);
        }
    }
    return dp[N];
}
int main(){
    int N=3;
    vector<int> dp(N+1,0);
    int c=countTrees(N,dp);
    cout<<c<<endl;
}