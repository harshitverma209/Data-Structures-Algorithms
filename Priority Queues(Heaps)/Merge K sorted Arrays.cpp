#include<bits/stdc++.h>
using namespace std;

class Num{
    public:
    int val;
    int row;
    int col;
    Num(int row, int col, int val){
        this->row = row;
        this->col = col;
        this->val = val;
    }
};
class NumCompare{
    public:
    bool operator()(Num a, Num b){
        return a.val > b.val;
    }
};
vector<int> mergeKArrays(vector<vector<int> > arrays){
    //Complete this function
    int N=arrays.size();
    priority_queue<Num, vector<Num>, NumCompare> heap;
    for(int i=0; i<N;i++){
        heap.push(Num(i,0,arrays[i][0]));
    }
    vector<int> res;
    while(!heap.empty()){
        Num num=heap.top();
        heap.pop();
        int row=num.row,col=num.col;
        if(arrays[row].size()>col+1){
            heap.push(Num(row,col+1,arrays[row][col+1]));
        }
        res.push_back(num.val);
    }
    return res;
    
}
int main(){
    vector<int> A={1,4,7,10};
    vector<int> B={2,5,8,11};
    vector<int> C={3,6,9,12};
    vector<vector<int> > arrays={A,B,C};
    vector<int> res=mergeKArrays(arrays);
    for(int x:res){
        cout<<x<<"\t";
    }
    return 0;
}