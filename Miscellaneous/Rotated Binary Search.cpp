/*The problem: to find the index of a particular element in 
a sorted array which has been rotated around a pivot element
Required Time Complexity:Logarithmic
*/
#include<iostream>
#include<vector>
using namespace std;
int rotated_binary_search(vector<int> arr,int k){
    int beg=0,end=arr.size()-1,mid=(beg+end)/2;
    while(beg<end){
        if(arr[mid]==k){
            return mid;
        }
        if(arr[mid]>arr[beg]){
            //Mid lies on Left monotonic curve/line
            if(k<arr[mid] && k>arr[beg]){
                //Key lies on left of mid
                end = mid;
                mid=(beg+end)/2;
            }else{
                //Key lies on right of mid
                beg=mid+1;
                mid=(beg+end)/2;
            }
        }else{
            //Mid lies on Right monotonic curve/line
            if(k>arr[mid] && k<arr[end]){
                //Key lies on right of mid
                beg=mid+1;
                mid=(beg+end)/2;
            }else{
                //Key lies on left of mid
                end=mid;
                mid=(beg+end)/2;
            }
        }
    }

    return -1;
}
int main(){
    vector<int> arr={3,4,5,6,7,8,0,1,2};
    int k=4;
    int res=rotated_binary_search(arr,k);
    cout<<res<<endl;
    return 0;
}
