//The problem is to find out the Kth smallest element in an array
#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int start, int end){
    int pivot_element=arr[end];
    int i=start-1,j=start;
    while(j<end){
        if(arr[j]<pivot_element){
            swap(arr[++i],arr[j]);
        }
        j++;
    }
    swap(arr[++i],arr[end]);
    return i;
}
int quick_select(vector<int> &arr,int start, int end, int k){
    if(start>=end){
        return arr[start];
    }
    int pivot=partition(arr, start, end);
    if(pivot==k){
        return arr[pivot];
    }
    else if(pivot<k){
        quick_select(arr,pivot+1,end,k);
    }else{
        quick_select(arr,start,pivot-1,k);
    }
}
int main(){
    vector<int> arr={2,4,1,5,22,12};
    int k=3;
    int end=arr.size()-1;
    cout<<quick_select(arr,0,end,k-1);
    return 0;
}