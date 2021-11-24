#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> stock_span(vector<int> prices){
    vector<int> span(prices.size());
    stack<int> S;
    for(int i = 0; i < prices.size(); i++){
        int price=prices[i];
        int count=1;
        while(!S.empty() and prices[S.top()]<price){
            S.pop();
            count++;
        }
        if(S.empty()){
            span[i]=max(1,i+1);
        }else{
            span[i]=i-S.top();
        }
        S.push(i);
    }
    return span;
}
int main(){
    vector<int> prices={100,80,60,70,60,75,85};
    vector<int> res=stock_span(prices);
    for(auto i:res){
        cout<<i<<endl;
    }
    return 0;
}