#include<iostream>
#include<vector>
using namespace std;
pair<char,int> GameOfWits(string s){
    int N=s.length();
    vector<vector<int>> dp(N+1,vector<int>(N+1,0));
    char p='O';
    int mul=1;
    for(int i=1;i<=N;i++){
        for(int j=N;j>=1;j--){
            mul=p=='O'?1:-1;
            if(i>j){
                dp[i][j]= mul*1;
            }
            else if(s[i-1]!=p and s[j-1]!=p){
                dp[i][j]=mul*(j-i+1);
            }
            else if(s[i-1]==p and s[j-1]==p){
                dp[i][j]=mul*max(dp[i-1][j],dp[i][j+1]);
            }else if(s[i-1]==p){
                dp[i][j]=mul*dp[i-1][j];
            }else{
                dp[i][j]=mul*dp[i][j+1];
            }
            p=(p=='O')?'H':'O';
        }
    }
    int ans=dp[1][N-1];
    p=ans<0?'H':'O';
    return {p,abs(ans)};
}
int main(){
    string s="HOOOOHH";
    pair<char,int> p=GameOfWits(s);
    cout<<p.first<<"\t"<<p.second;
    // for(auto r:dp){
    //     for(auto p:r){
    //         cout<<'('<<p.first<<','<<p.second<<')'<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<p.first<<"\t"<<p.second;
    return 0;
}