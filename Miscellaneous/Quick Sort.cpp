#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr,int start,int end){
    int i=start-1,j=start,pivot_element=arr[end];
    while(j<end){
        if(arr[j]<pivot_element){
            swap(arr[++i],arr[j]);
        }
        j++;
    }
    swap(arr[++i],arr[end]);
    return i;
}
void quick_sort(vector<int> &arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivot=partition(arr,start,end);
    quick_sort(arr,start,pivot-1);
    quick_sort(arr,pivot+1,end);
    
}
int main(){
    vector<int> arr={9,7,4,5,21,11};
    int end=arr.size()-1;
    quick_sort(arr,0,end);
    for(int ele:arr){
        cout<<ele<<endl;
    }
    return 0;
}