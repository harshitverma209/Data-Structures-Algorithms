#include<iostream>
#include<vector>
using namespace std;
bool patternMatching(string s, string p, int M,int N, vector<vector<int>> &dp){
    //N:Pattern length
    //Base Case
    if(N<0){
        return true;
    }
    if(M<0){
        if(p[N]=='*'){
            return patternMatching(s,p,M,N-1,dp);
        }
        return false;
    }
    //Recursive Case
    if(dp[M][N]!=-1){
        return dp[M][N];
    }
    if(p[N]=='*'){
        return dp[M][N]=patternMatching(s,p,M,N-1,dp) or patternMatching(s,p,M-1,N,dp);
    }
    if(p[N]==s[M] or p[N]=='?'){
        return dp[M][N]=patternMatching(s,p,M-1,N-1,dp);
    }
    return dp[M][N]=false;
}
int main(){
    string s="baaabab";
    string p="**ba*b*ab";
    int M=s.length();
    int N=p.length();
    vector<vector<int> > dp(M+1,vector<int>(N+1,-1));
    bool res=patternMatching(s,p,M-1,N-1,dp);
    for(auto r:dp){
        for(auto c:r){
            cout<<c<<"\t";
        }
        cout<<endl;
    }
    cout<<res;
    return 0;
}