#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minMergeCost(vector<int> ropes){
    priority_queue<int,vector<int>,greater<int>> heap(ropes.begin(), ropes.end());
    int cost=0;
    while(heap.size()>1){
        int r1=heap.top();
        heap.pop();
        int r2=heap.top();
        heap.pop();
        cost+=r1+r2;
        heap.push(r1+r2);
    }
    return cost;
}
int main(){
    int N;
    cin>>N;
    vector<int> ropes;
    for(int i=0;i<N;i++){
        int rope;
        cin>>rope;
        ropes.push_back(rope);
    }
    cout<<minMergeCost(ropes);
    return 0;
}