#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> findCommon(vector<int> v1, vector<int> v2){
    vector<int> res;
    set<int> s1,s2;
    for(int x:v1){
        s1.insert(x);
    }
    for(int x:v2){
        s2.insert(x);
    }
    for(int x:s1){
        if(s2.find(x) != s2.end()){
            res.push_back(x);
        }
    }
    return res;
}
int main(){
    vector<int> v1={1,2,3,4,5,6,7,8};
    vector<int> v2={2,4,6,7,9,10};
    vector<int> res=findCommon(v1,v2);
    for(int x:res){
        cout<<x<<"\t";
    }
    return 0;
}