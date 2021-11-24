#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
vector<char> findFirstNonRepeatingCharacter(string str){
    int freq[27]={0};
    vector<char> result;
    queue<char> q;
    for(char c:str){
        q.push(c);
        freq[c-'a']++;
        while(!q.empty()){
            char qc=q.front();
            if(freq[qc-'a']>1){
                q.pop();
            }else{
                result.push_back(qc);
                break;
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