#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lIS(vector<int> arr){
    int N=arr.size();
    vector<int> dp(N,1);
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main(){
    vector<int> arr={50,4,10,8,30,100};

    int res=lIS(arr);
    cout<<res<<endl;
    return 0;
}