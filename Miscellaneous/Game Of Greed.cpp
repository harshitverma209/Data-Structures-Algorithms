/*The problem: To distribute N coins among k people such that the min amount is the maximum.
The coins can only be distributed in a consective fashion i.e.
you can only pick one coin at a time and that too, the first coin.
*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool can_distribute(vector<int> coins, int min_amt, int friends){
    int currSum =0;
    for(int i = 0; i < coins.size(); i++){
        currSum += coins[i];
        if(currSum>= min_amt){
            currSum=0;
            friends--;
            if(friends<=0){
                return true;
            }
        }
    }
    return false;
}
int get_coins(vector<int> coins, int k){
    int end=accumulate(coins.begin(),coins.end(),0);
    int beg=*min_element(coins.begin(),coins.end());
    int res=-1;
    int mid=(beg+end)/2;
    while(beg<end){
        if(can_distribute(coins,mid,k)){
            res=max(res,mid);
            beg=mid+1;
        }else{
            end=mid;
        }
        mid=(beg+end)/2;
    }
    return res;
}
int main(){
    vector<int> coins={5,1,3,2,4};
    int k=3;
    int res=get_coins(coins,k);
    cout<<res<<endl;
    return 0;
}