#include<iostream>
#include<vector>
using namespace std;
int countSteps(int n,int k){
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
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