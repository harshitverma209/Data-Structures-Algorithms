#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs){
    //Write your code here. Do not modify the function or the parameters. 
    vector<vector<string>> res;
    map<vector<int>,vector<string>> hashes;
    for(string str:strs){
        vector<int> freq(26,0);
        for(char c:str){
            freq[c-'a']++;
        }
        hashes[freq].push_back(str);
    }
    for(auto p:hashes){
        res.push_back(p.second);
    }
    return res;
}
int main(){
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res=groupAnagrams(strs);
    for(auto row:res){
        for(string str:row){
            cout<<str<<"\t";
        }
        cout<<endl;
    }
    return 0;
}