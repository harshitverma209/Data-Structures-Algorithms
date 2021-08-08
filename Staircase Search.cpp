/*The problem:
In a 2D matrix which is row sorted and column sorted, find a specific element
In Linear time*/
#include<iostream>
#include<vector>

using namespace std;
pair<int,int> staircase_search(int m,int n,vector<vector<int>> arr,int k){
    int i=0,j=n-1;
    while(i<m && j>0){
        int curr=arr[i][j];
        if(curr==k){
            return make_pair(i,j);
        }else if(curr>k){
            j--;
        }else{
            i++;
        }
    }
    return make_pair(-1,-1);
}
int main(){
    vector<vector<int>> arr={{1,4,9},{2,5,10},{6,7,11}};
    int m=3,n=3,k=5;
    auto result=staircase_search(m,n,arr,k);
    cout<<result.first<<","<<result.second;
    return 0;
}