#include<iostream>
#include<vector>
using namespace std;
int countSubsequences(string s1, string s2){
    int M=s1.length();
    int N=s2.length();
    vector<vector<int>> dp(M+1,vector<int>(N+1,0));
    for(int i=0;i<M;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // for(auto r:dp){
    //     for(auto c:r){
    //         cout<<c<<"\t";
    //     }
    //     cout<<endl;
    // }
    return dp[M][N];
}
int main(){
    string s1="ABCDCE";
    string s2="ABC";
    int res=countSubsequences(s1,s2);
    cout<<res<<endl;
    return 0;
}