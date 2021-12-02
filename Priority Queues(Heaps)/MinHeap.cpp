#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>> heap;
    int arr[]={2,3,5,1,9,6,7};
    for(int i:arr){
        heap.push(i);
    }
    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }
    return 0;
}