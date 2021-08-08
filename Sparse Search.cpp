/*The problem:
In a sorted array of strings, find the index of a particular search string.
The array also has some invalid(empty) strings inside it.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int sparse_search(vector<string> arr,string st){
    int beg=0,end=arr.size()-1;
    for(int beg=0;beg<=end;){
        int mid=(beg+end)/2;
        int i=0;
        while(arr[mid]==""){
            if(arr[mid+i]!=""){
                mid=mid+i;
            }else if(arr[mid-i]!=""){
                mid=mid-i;
            }
            i++;
        }
        if(arr[mid]==st){
            return mid+1;
        }else if(arr[mid]<st){
            beg=mid+1;
        }else{
            end=mid-1;
        }
    }
}
int main(){
    vector<string> arr={"","bat","","","","cat","cow","","dog"};
    string search_term="bat";
    cout<<sparse_search(arr,search_term);
    return 0;
}