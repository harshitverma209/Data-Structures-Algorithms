#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,int start, int end){
    int i=start,mid=(start+end)/2,j=mid+1;
    vector<int> temp;
    while(i<=mid &&j<=end){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    int k=0;
    for(int i=start;i<=end;i++){
        arr[i]=temp[k++];
    }
}
void merge_sort(vector<int> &arr, int start, int end){
    if(start>=end){
        return;
    }
    int mid=(start+end)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    return merge(arr,start,end);
}
int main(){
    vector<int> arr={2,19,9,20,12,18};
    merge_sort(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<endl;
    }
    return 0;
}