#include<iostream>
#include<vector>
using namespace std;
bool patternMatching(string s, string p){
    //N:Pattern length
    int M=s.length();
    int N=p.length();
    vector<vector<int> > dp(M+1,vector<int>(N+1,0));
    //Base Case
    // for(int i=0;i<M;i++){
    //     dp[i][0]=true;
    // }
    dp[0][0]=true;
    for(int i=1;i<N;i++){
        if(p[i-1]!='*'){
            dp[0][i]=false;
        }else{
            dp[0][i]=dp[0][i-1];
        }
    }

    // if(M<0){
    //     if(p[N]=='*'){
    //         return patternMatching(s,p,M,N-1,dp);
    //     }
    //     return false;
    // }
    //Recursive Case
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-1] or dp[i-1][j];
            }else if(p[j-1]==s[i-1] or p[j-1]=='?'){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=false;
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
    string s="baaabab";
    string p="**ba**ab";
    
    bool res=patternMatching(s,p);

    cout<<res;
    return 0;
}