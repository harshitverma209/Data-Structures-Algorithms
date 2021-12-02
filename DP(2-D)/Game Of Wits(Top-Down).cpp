#include<iostream>
#include<vector>
using namespace std;
bool Comp(pair<char,int> a,pair<char,int> b){
    return a.second < b.second;
}
pair<char,int> goW(string s,char p, int i, int j, vector<vector<pair<char,int>>> &dp){
    char o=(p=='O')?'H':'O';
    //Base Case
    if(i>j){
        return {o,1};
    }
    if(s[i]!=p and s[j]!=p){
        return {o,j-i+2};
    }
    // Recursive Case
    if(dp[i][j].first!='\0'){
        return dp[i][j];
    }

    if(s[i]==p and s[j]==p){
        pair<char,int> pickLeft=goW(s,o,i+1,j,dp);
        pair<char,int> pickRight=goW(s,o,i,j-1,dp);
        if(pickLeft.first==p and pickRight.first==p){
            //Win in both cases

            return  dp[i][j]={p,max(pickLeft,pickRight,Comp).second};
        }else if(pickLeft.first==p){
            //Win if pick Left
            return dp[i][j]={p,pickLeft.second};
        }else if(pickRight.first==p){
            //Win if pick Right
            return dp[i][j]={p,pickRight.second};
        }else{
            //Can not Win
            return dp[i][j]={o,min(pickLeft,pickRight,Comp).second};
        }
    }else if(s[i]==p){
        //Can only Pick Left
        pair<char,int> pickLeft=goW(s,o,i+1,j,dp);
        return dp[i][j]=pickLeft;
    }else{
        //Can Only Pick Right
        pair<char,int> pickRight=goW(s,o,i,j-1,dp);
        return dp[i][j]=pickRight;
    }
}
int main(){
    string s="OHOHHO";
    int N=s.length();
    vector<vector<pair<char,int>>> dp(N+1,vector<pair<char,int>>(N+1,pair<char,int>('\0',0)));
    pair<char,int> p=goW(s,'O',0,N-1,dp);
    for(auto r:dp){
        for(auto p:r){
            cout<<'('<<p.first<<','<<p.second<<')'<<"\t";
        }
        cout<<endl;
    }
    cout<<p.first<<"\t"<<p.second;
    return 0;
}