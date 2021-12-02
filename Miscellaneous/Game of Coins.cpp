#include<iostream>
#include<vector>
using namespace std;
int find_max_value(vector<int> coins, int i, int j){
    //Base Case
    if(j==i){
        return coins[i];
    }
    if(j==i+1){
        return max(coins[i], coins[j]);
    }
    //Recurcive Case
    return max(coins[i]+min(find_max_value(coins,i+2,j),find_max_value(coins,i+1,j-1)),
                coins[j]+min(find_max_value(coins,i,j-2),find_max_value(coins,i+1,j-1)) 
            );

}
int MaxValue(int N, vector<int> coins){
    int res=find_max_value(coins,0,N-1);
    return res;
}
int main(){
    vector<int> coins={8,15,3,7};
    int n=coins.size();
    int res= MaxValue(n,coins);
    cout<<res;
    return 0;
}