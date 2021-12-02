#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int min_array_jumps(vector<int> arr){
    int N=arr.size();
    vector<int> dp(N,INT_MAX);
    dp[N-1]=0;
    for(int i=N-1;i>=0;i--){
        
        for(int jump=1;jump<=arr[i] && i+jump<N;jump++){
            
            dp[i]=min(dp[i+jump]+1,dp[i]);
            
        }
        
    }
    return dp[0];
}
int main(){
    vector<int> arr={3,4,2,1,2,3,7,1,1,1,2,5};
    int res=min_array_jumps(arr);
    cout<<res;
    return 0;
}