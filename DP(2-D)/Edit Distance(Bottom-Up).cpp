#include<iostream>
#include<vector>
using namespace std;
int editDistance(string s1,string s2){
    int M=s1.length();
    int N=s2.length();
    vector<vector<int> > dp(M+1,vector<int>(N+1,0));
    for(int i=0;i<=M;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=N;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                int replace=dp[i-1][j-1];
                int remove=dp[i][j-1];
                int insert=dp[i-1][j];
                dp[i][j]=1+min(insert,min(remove,replace));
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
    string s1="saturday",s2="sunday";
    int res=editDistance(s1,s2);
    cout<<res<<endl;
    return 0;
}