#include<iostream>
#include<vector>
using namespace std;
int countSubsequences(string s1, string s2, int i, int j, vector<vector<int>> &dp){
    //Base Case
    if(j==-1){
        return 1;
    }
    if(i==-1){
        return 0;
    }
    // Recursive Case
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=countSubsequences(s1,s2,i-1,j-1,dp)+countSubsequences(s1,s2,i-1,j,dp);
    }
    return dp[i][j]=countSubsequences(s1,s2,i-1,j,dp);
}
int main(){
    string s1="ABCDC";
    string s2="ABC";
    int M=s1.length();
    int N=s2.length();
    vector<vector<int>> dp(M+1,vector<int>(N+1,0));
    int res=countSubsequences(s1,s2,M,N,dp);
    // for(auto r:dp){
    //     for(auto c:r){
    //         cout<<c<<"\t";
    //     }
    //     cout<<endl;
    // }
    cout<<res<<endl;
    return 0;
}