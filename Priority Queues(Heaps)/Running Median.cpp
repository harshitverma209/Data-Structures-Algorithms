#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void runningMedian(){
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>, greater<int> > min_heap;
    int d;
    cin>>d;
    max_heap.push(d);
    float med=d;
    cout<<med<<"\t";
    cin>>d;
    while(d!=-1){
        if(max_heap.size()>min_heap.size()){
            if(d<med){
                int x=max_heap.top();
                max_heap.pop();
                min_heap.push(x);
                max_heap.push(d);
            }else{
                min_heap.push(d);
            }
            med=(max_heap.top()+min_heap.top())/2.0;
        }else if(max_heap.size()==min_heap.size()){
            if(d<med){
                max_heap.push(d);
                med=max_heap.top();
            }else{
                min_heap.push(d);
                med=min_heap.top();
            }
        }else{
            if(d>med){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(d);
            }else{
                max_heap.push(d);
            }
            med=(max_heap.top()+min_heap.top())/2.0;
        }
    cout<<med<<"\t";
    cin>>d;
    }
}
int main(){
    runningMedian();
    //10 5 2 3 0 12 18 20 22 -1
    return 0;
}