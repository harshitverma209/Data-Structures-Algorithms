#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxNonAdjSum(vector<int> arr, int i, int N, vector<int> &dp){
    //Base Case
    if(i==N-1){
        return arr[i];
    }
    if(i>N-1){
        return 0;
    }
    //Recursive Case
    if(dp[i]==INT_MIN){
        int op1=maxNonAdjSum(arr,i+2,N,dp)+arr[i];
        int op2=maxNonAdjSum(arr,i+1,N,dp);
        dp[i]=max(op1,op2);
    }
    return dp[i];

}
int main(){
    vector<int> arr={6,10,12,7,9,14};
    int N=arr.size();
    vector<int> dp(N,INT_MIN);
    int res=maxNonAdjSum(arr,0,N,dp);
    cout<<res<<endl;
    return 0;
}