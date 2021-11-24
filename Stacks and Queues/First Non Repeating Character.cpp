#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
vector<char> findFirstNonRepeatingCharacter(string str){
    vector<char> result;
    queue<char> q;
    unordered_map<char,int> fmap;
    for(char c:str){
        q.push(c);
        if(fmap.find(c)!=fmap.end()){
            fmap[c]++;
        }else{
            fmap[c]=1;
        }
        while(!q.empty()){
            char qc=q.front();
            auto ele=fmap.find(qc);
            if(ele != fmap.end()){
                int freq=ele->second;
                if(freq>1){
                    q.pop();
                }else{
                    result.push_back(qc);
                    break;
                }
            }
        }
        if(q.empty()){
            result.push_back('0');
        }
    }
    return result;
}
int main(){
    string str="aabbssbbasiaas";
    vector<char> res=findFirstNonRepeatingCharacter(str);
    for(auto c:res){
        cout<<c;
    }
    return 0;
}