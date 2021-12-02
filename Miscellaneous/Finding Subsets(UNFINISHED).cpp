#include<iostream>
#include<vector>
int find_subsets(vector<int> set){
    if(set.size()==0){
        return 1;
    }
    return find_subsets(set)
}
int main(){
    vector<int> set={1,2,3};
    int res=find_subsets(set);
    cout<<res;
    return 0;
}