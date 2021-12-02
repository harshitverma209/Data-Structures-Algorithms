/*The problem:
To calculate the number of ways in which 
a person can climb a ladder of N steps
if he can make a jump of 1,2, or 3 steps 
in one time*/
#include<iostream>
#include<vector>
using namespace std;
int countSteps(int n,int k,vector<int> &dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=0;
    for(int j=1;j<=k;j++){
        dp[n]+=countSteps(n-j,k,dp);
    }
    return dp[n];
}
int main(){
    int n=10,k=3;
    vector<int> dp(n+1,-1);
    int res=countSteps(n,k,dp);
    cout<<res;
    return 0;
}