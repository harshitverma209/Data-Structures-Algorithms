#include<iostream>
#include<vector>
using namespace std;
int cutting_rods(vector<int> prices, int tl, vector<int> &dp){
    if(tl==0){
        return 0;
    }
    int mp=0;
    for(int i=0;i<prices.size();i++){
        int length=i+1;
        int price=prices[i];
        if(tl>=length){
            if(dp[tl-length]==-1){
                dp[tl-length]=cutting_rods(prices,tl-length,dp);
            }
            mp=max(mp,dp[tl-length]+price);
        }

    }
    return mp;
}
int main(){
    vector<int> prices={1,5,8,9,10,17,17,20};
    int tl=8;
    vector<int> dp(tl,-1);
    int max_profit=cutting_rods(prices,tl,dp);
    cout<<max_profit;
    return 0;
}