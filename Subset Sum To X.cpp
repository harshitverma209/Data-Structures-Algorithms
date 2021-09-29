/*The problem:
Given an array,
To find the number 
of all possible subsets 
that sum up to 'SUM'
*/
#include<iostream>
#include<vector>
using namespace std;
int count_subsets(vector<int> arr, int n, int i, int sum){
    if(i==n){
        if(sum==0){
            return 1;
        }
        return 0;
    }
    int inc=count_subsets(arr,n,i+1,sum-arr[i]);
    int exc=count_subsets(arr,n,i+1,sum);
    return inc+exc;
}
int main(){
    vector<int> arr={1,2,3,4,5};
    int sum=6;
    int res=count_subsets(arr,arr.size(),0,sum);
    cout<<res<<endl;
    return 0;
}