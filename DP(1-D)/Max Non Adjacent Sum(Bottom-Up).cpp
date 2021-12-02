#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxNonAdjSum(vector<int> arr){
    int N=arr.size();
    vector<int> dp(N+1,INT_MIN);
    dp[N-1]=arr[N-1];
    for(int i=N-2;i>=0;i--){
        int op1=dp[i+2]+arr[i];
        int op2=dp[i+1];
        dp[i]=max(op1,op2);
    }
    return dp[0];

}
int main(){
    vector<int> arr={6,10,12,7,9,14};
    int res=maxNonAdjSum(arr);
    cout<<res<<endl;
    return 0;
}