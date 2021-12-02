#include<iostream>
#include<vector>
using namespace std;
int cutting_rods(vector<int> prices, int tl){
    vector<int> dp(tl+1,0);
    for(int i=1;i<=tl;i++){
        for(int j=0;j<i;j++){
            int cut=j+1;
            dp[i]=max(dp[i-cut]+prices[j],dp[i]);
        }
    }
    return dp[tl];
}
int main(){
    vector<int> prices={1,5,8,9,10,17,17,20};
    int tl=8;
    int max_profit=cutting_rods(prices,tl);
    cout<<max_profit;
    return 0;
}