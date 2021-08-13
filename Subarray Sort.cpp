/*The problem:
Given an unsorted array, find the starting and ending indices of the smallest subarray that 
must be sorted so that the whole array becomes sorted.
The algorithm should take linear time(O(n)) and constant space(O(1))
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool outOfOrder(vector<int> arr,int index){
    int x=arr[index];
    if(index==0){
        return x>arr[index+1];
    }
    if(index==arr.size()-1){
        return x<arr[index-1];
    }
    return x>arr[index+1] || x<arr[index-1];
}
pair<int, int> subarraySorting(vector<int> arr){
    int smallest_out_of_order=INT_MAX;
    int largest_out_of_order=INT_MIN;
    int small_index,large_index;
    for(int i=0;i<arr.size();i++){
        if(outOfOrder(arr,i)){
            smallest_out_of_order=min(smallest_out_of_order,arr[i]);
            largest_out_of_order=max(largest_out_of_order,arr[i]);
        }
    }
    if(smallest_out_of_order==INT_MAX){
        return make_pair(-1,-1);
    }
    int left=0;
    while(arr[left]<smallest_out_of_order){
        left++;
    }
    int right=arr.size()-1;
    while(arr[right]>largest_out_of_order){
        right--;
    }
    return make_pair(left,right);
}
int main(){
    vector<int> arr={0,2,4,7,10,11,7,12,13,14,16,19,29};
    pair<int,int> result=subarraySorting(arr);
    cout<<result.first<<" "<<result.second;
    return 0;
}