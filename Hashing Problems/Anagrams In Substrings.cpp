#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> getHash(string str, int i, int j) {
    vector<int> hash(26,0);
    for(;i<=j;i++){
        char c=str[i];
        hash[c-'a']++;
    }
    return hash;
}
int countAnagramSubstrings(string str){
    int count=0;
    map<vector<int>,int> hashes;
    for(int i=0; i<str.length();i++){
        for(int j=i; j<str.length();j++){
            // cout<<str.substr(i,j)<<endl;
            vector<int> hash=getHash(str,i,j);
            hashes[hash]++;
        }
    }
    for(pair<vector<int>,int> p:hashes){
        int freq=p.second;
        if(freq>=2){
            count+=(((freq)*(freq-1))/2);
        }
    }
    return count;
}
int main(){
    string str="abba";
    int c=countAnagramSubstrings(str);
    cout<<c;
    return 0;
}