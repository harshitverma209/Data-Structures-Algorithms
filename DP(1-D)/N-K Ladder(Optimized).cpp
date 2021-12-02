#include<iostream>
#include<vector>
using namespace std;
int countSteps(int n,int k){
    int dp[n+1];
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i<=k){
            dp[i]=2*dp[i-1];
        }else{
            dp[i]=(2*dp[i-1])-dp[i-k-1];
        }
    }
    return dp[n];
}
int main(){
    int n=10,k=3;
    int res=countSteps(n,k);
    cout<<res;
    return 0;
}