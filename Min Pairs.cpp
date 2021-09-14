/*The problem: Given two arrays, find out the 
pair of elements (one from each) with the lease absolute difference*/
#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

pair<int, int> min_pairs(vector<int> arr1,vector<int> arr2){
    int res=INT_MAX,p1=-1,p2=-1;
    sort(arr1.begin(),arr1.end());
    for(int i=0;i<arr2.size();i++){
        int ele=arr2[i];
        int up=lower_bound(arr1.begin(),arr1.end(),ele)-arr1.begin();
        if(up<arr1.size()){
            int bigger_ele=arr1[up];
            if(res>(bigger_ele-ele)){
                p1=ele;
                p2=bigger_ele;
                res=bigger_ele-ele;
            }
        }
        if(up>0){
            int smaller_ele=arr1[up-1];
            if(res>(ele-smaller_ele)){
                p1=smaller_ele;
                p2=ele;
                res=ele-smaller_ele;
            }
        }
    }
    return {p1,p2};
}

int main(){
    vector<int> arr1={-1,5,10,20,3};
    vector<int> arr2={26,134,135,15,17};
    pair<int,int> res=min_pairs(arr1,arr2);
    cout<<res.first<<" and "<<res.second<<endl;
    return 0;
}