#include<iostream>
#include<vector>
using namespace std;
int cross_inversions(vector<int> &arr,int start,int end){
    int count=0;
    int i=start,mid=(start+end)/2,j=mid+1;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            count+=mid-i+1;
            temp.push_back(arr[j++]);
        }else{
            temp.push_back(arr[i++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while (j<=end)
    {
        temp.push_back(arr[j++]);
    }
    int k=0;
    for(int i=start;i<=end;i++){
        arr[i]=temp[k++];
    }
    return count;
}
int inversion_count(vector<int> &arr,int start,int end){
    if(start>=end){
        return 0;
    }
    int mid=(start+end)/2;

    int c1=inversion_count(arr,start,mid);
    int c2=inversion_count(arr,mid+1,end);
    int c3=cross_inversions(arr,start,end);
    return c1+c2+c3;
        
}
int main(){
    vector<int> arr={9,1,2,31};
    int end=arr.size()-1;
    int count=inversion_count(arr,0,end);
    cout<<count;
    return 0;
}