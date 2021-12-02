#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countGPTriplets(vector<int> arr,int r){
    unordered_map<int,int> leftPart,rightPart;
    int count=0;
    for(int i=0;i<arr.size();i++){
        rightPart[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++){
        long a=arr[i];
        rightPart[a]--;
        long abyr=a/r;
        long ar=a*r;
        count+=(leftPart[abyr]*rightPart[ar]);
        leftPart[a]++;
    }
    return count;
}
int main(){
    vector<int> arr={1,16,4,16,64,16};
    int r=4;
    int res=countGPTriplets(arr,r);
    cout<<res;
    return 0;
}