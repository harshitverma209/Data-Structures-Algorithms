#include<iostream>
#include<vector>
using namespace std;
int sum(vector<int> arr,int start, int count){
    int sum=0;
    for(int i=start; i<start+count; i++){
        sum+=arr[i];
    }
    // cout<<sum<<" aaya"<<endl;
    return sum;
}
int find_max_value(vector<int> coins, int i, int j, int k){
    //Base Case
    if(k>j-i+1){
        // cout<<"BASE1:\t";
        return sum(coins,i,k-(j-i));
    }
    if(k==j-i+1){
        // cout<<"Baeeee 2:\t";
        return max(sum(coins,i,k), sum(coins,j-k+1,k));
    }
    //Recursive Case
    // cout<<"Recursive:\t";
    return max(sum(coins,i,k)+min(find_max_value(coins,i+2*k,j,k),find_max_value(coins,i+k,j-k,k)),
                sum(coins,j-k+1,k)+min(find_max_value(coins,i,j-(2*k),k),find_max_value(coins,i+k,j-k,k)) 
            );

}
int MaxValue(int N, vector<int> coins, int k){
    int res=find_max_value(coins,0,N-1,k);
    return res;
}
int main(){
    vector<int> coins={10,15,20,9,2};
    int n=coins.size(),k=1;
    int res= MaxValue(n,coins,k);
    cout<<res;
    return 0;
}