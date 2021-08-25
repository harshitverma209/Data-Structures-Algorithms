/*The problem is to find the number of occurences of a "key" in a sorted array in logarithmic time*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int find_occurrence(vector<int> arr,int key,string type="first"){
    int beg=0,end=arr.size(),mid=(beg+end)/2;
    int ans=-1;
    while(beg<=end){
        if(arr[mid]==key){
            ans=mid;  
            if(type=="first"){      
                end=mid-1;
            }else{
                beg=mid+1;
            }
            mid=(beg+end)/2;
        }else{
            if(arr[mid]>key){
                end=mid-1;
                mid=(beg+end)/2;
            }else{
                beg=mid+1;
                mid=(beg+end)/2;
            }
        }

    }
    return ans;
}


int main(){
    vector<int> arr={1,2,2,2,2,3,4,4,4,4,4,5,6,7,8,9,9};
    int key = 4;
    int fo=find_occurrence(arr,key,"first");
    int lo=find_occurrence(arr,key,"last");
    cout<<lo-fo+1;
    return 0;
}