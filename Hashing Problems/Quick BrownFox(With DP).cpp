#include<iostream>
#include<climits>
#include<vector>
#include<unordered_set>
using namespace std;
int minBarsHelper(string str, vector<string> words, int idx, unordered_set<string> &m, vector<int> &dp){
    //Base Case
    if(str[idx]=='\0'){
        return 0;
    }
    //Recursive Case
    int ans=INT_MAX;
    string current_string="";
    if(idx<dp.size()){
        ans=dp[idx];
    }else{
        for(int i= idx;i<str.length();i++){
            current_string+=str[i];
            if(m.find(current_string)!=m.end()){
                int rem_ans=minBarsHelper(str, words,i+1,m,dp);
                if(rem_ans!=-1){
                    ans=min(ans,1+rem_ans);
                    dp.push_back(ans);
                }
            }
        }
    }
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
}
int minBars(string str, vector<string> words){
    unordered_set<string> m;
    for(string word:words){
        m.insert(word);
    }
    vector<int> dp;
    int bars=minBarsHelper(str, words, 0, m,dp);
    return bars-1;
}
int main(){
    string str="thequickbrownfoxjumpsoverthehighbridge";
    vector<string> words={"the","fox","thequickbrownfox","jumps","lazy","lazyfox","highbridge","the","over","bridge","high","tall","quick","brown"};
    int bars=minBars(str,words);
    cout<<bars<<endl;
    return 0;
}