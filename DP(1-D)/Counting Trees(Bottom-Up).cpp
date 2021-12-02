#include<iostream>
#include<vector>
using namespace std;
int countTrees(int N){
    vector<int> dp(N+1,0);
    dp[0] = dp[1] = 1;
    for(int i=2; i<=N; i++){
        for(int j=1;j<=i;j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    return dp[N];
}
int main(){
    int N=3;
    int c=countTrees(N);
    cout<<c<<endl;
}