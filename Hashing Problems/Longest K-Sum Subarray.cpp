#include<bits/stdc++.h>
using namespace std;

int longestSubarrayKSum(vector<int> arr,int k){
    //Complete this function and return the length of longest subarray
    unordered_map<int,int> m;
    int maxLength=0;
    int currentSum=0;
    for(int i=0;i<arr.size();i++){
        int x=arr[i];
        currentSum+=x;
        if(currentSum==k){
            maxLength=max(maxLength,i+1);
        }else{
            if(m.find(currentSum-k)!=m.end()){
                maxLength=max(maxLength,i-m[currentSum-k]);
            }else{
                m[currentSum]=i;
            }
        }
    }
    return maxLength;
    
}
int main(){
    vector<int> arr={0,-2,1,2,3,4,5,15,10,5};
    int k=15;
    int count=longestSubarrayKSum(arr,k);
    cout<<count<<endl;
    return 0;
}