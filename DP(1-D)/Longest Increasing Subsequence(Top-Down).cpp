#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lIS(vector<int> arr, int N, int i, vector<int> &dp){
    //Base Case
    if(i==N-1){
        return dp[i]=1;
    }
    //Recursive Case
    if(dp[i]==0){
        int m=1;
        for(int j=i+1;j<N;j++){
            m=lIS(arr,N,j,dp)+1;
            if(arr[i]<arr[j]){
                dp[i]=max(dp[i],m);
            }
        }
    }
    return dp[i];
}
int main(){
    vector<int> arr={50,4,10,8,30,100};
    int N=arr.size();
    vector<int> dp(N,0);
    lIS(arr,N,0,dp);
    int res=*max_element(dp.begin(),dp.end());
    cout<<res<<endl;
    return 0;
}