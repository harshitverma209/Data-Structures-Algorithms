#include<iostream>
#include<vector>
using namespace std;
int editDistance(string s1,string s2, int i, int j, vector<vector<int> > &dp){
    //Base Case
    if(i==0 or j==0){
        return max(i,j);
    }
    //Recursive Case
    if(dp[i][j]==0){
        if(s1[i]==s2[j]){
            dp[i][j]= editDistance(s1,s2,i-1,j-1,dp);
        }else{
            int replace=editDistance(s1,s2,i-1,j-1,dp);
            int remove=editDistance(s1,s2,i,j-1,dp);
            int insert=editDistance(s1,s2,i-1,j,dp);
            dp[i][j]=1+min(insert,min(remove,replace));
        }
    }
    return dp[i][j];
}
int main(){
    string s1="saturday",s2="sunday";
    int M=s1.length();
    int N=s2.length();
    vector<vector<int> > dp(M+1,vector<int>(N+1,0));
    int res=editDistance(s1,s2,M-1,N-1,dp);
    cout<<res<<endl;
    return 0;
}