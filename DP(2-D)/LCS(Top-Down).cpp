#include<iostream>
#include<vector>
using namespace std;
int lcs(string s1, string s2, int i, int j,vector<vector<int>> &dp){
    //Base Case
    if(i==s1.length() || j==s2.length()){
        return 0;
    }
    //Recursive Case
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=1+lcs(s1,s2,i+1,j+1,dp);
    }
    return dp[i][j]=max(lcs(s1,s2,i+1,j,dp),lcs(s1,s2,i,j+1,dp));
}
int main(){
    string s1="HELLO WORLD";
    string s2="JELLO CURD";
    int M=s1.length();
    int N=s2.length();
    vector<vector<int> > dp(M,vector<int>(N,-1));
    int lcsLength=lcs(s1,s2,0,0,dp);
    cout<<lcsLength<<endl;
    return 0;
}