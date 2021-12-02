#include<iostream>
#include<vector>
using namespace std;
int lcs(string s1, string s2){
    int M=s1.length();
    int N=s2.length();
    vector<vector<int> > dp(M+1,vector<int>(N+1,0));
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    vector<char> result;
    int i=M,j=N;
    while(i!=0 and j!=0){
        if(dp[i][j]==dp[i][j-1]){
            j--;
        }else if(dp[i][j]==dp[i-1][j]){
            i--;
        }else{
            result.push_back(s1[i-1]);
            i--; j--;
        }
    }        

    for(int i=result.size();i>=0;i--){
        cout<<result[i];
    }
    return dp[M][N];
}
int main(){
    string s1="HELLO WORLD";
    string s2="JELLO CURD";
    
    int lcsLength=lcs(s1,s2);
    cout<<endl<<lcsLength<<endl;
    return 0;
}