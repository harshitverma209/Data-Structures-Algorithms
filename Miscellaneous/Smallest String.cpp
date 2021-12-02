/*The problem:
Given an array of strings, 
concatenate them in such a way that the 
resulting string is lexographiically smallest.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool lexo_sort(string a, string b){
    return a+b<b+a;
}
int main(){
    vector<string> arr={"c","cb","cba"};
    sort(arr.begin(),arr.end(),lexo_sort);
    for(string s:arr){
        cout<<s;
    }
    return 0;
}