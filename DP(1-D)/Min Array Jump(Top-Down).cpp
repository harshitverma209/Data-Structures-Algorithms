#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int min_array_jumps(vector<int> arr,int i,vector<int> &dp){
    //Base Case
    if(i==arr.size()-1){
        return 0;
    }
    if(i>=arr.size()){
        return INT_MAX;
    }
    //Recursive Case
    if(dp[i]==INT_MAX){
        for(int jump=1;jump<=arr[i];jump++){
            
            dp[i]=min(min_array_jumps(arr,i+jump,dp)+1,dp[i]);
            
        }
    }
    return dp[i];
}
int main(){
    vector<int> arr={3,4,2,1,2,3,7,1,1,1,2,5};
    vector<int> dp(arr.size(),INT_MAX);
    int res=min_array_jumps(arr,0,dp);
    cout<<res;
    return 0;
}