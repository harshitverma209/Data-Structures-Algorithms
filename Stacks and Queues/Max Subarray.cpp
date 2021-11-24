#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> max_subarray(vector<int> arr, int n, int k){
    deque<int> q(k);
    vector<int> res;
    int i=0;
    for(i=0;i<k;i++){
        while(!q.empty() && arr[i]>arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<=n;i++){
        res.push_back(arr[q.front()]);
        while(!q.empty() && q.front()<=i-k){
            q.pop_front();
        }
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    return res;
}
int main(){
    vector<int> arr={1,2,3,1,4,5,2,3,1,5};
    int k=3;
    vector<int> res=max_subarray(arr,arr.size(),k);
    for(auto i:res){
        cout<<i<<endl;
    }
}