#include<iostream>
#include<deque>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
string simplifyPath(string path){
    istringstream iss(path);
    vector<string> tokens;
    string token;
    deque<string> Q;
    while(getline(iss, token,'/')){
        if(token=="." || token==""){
            continue;
        }
        tokens.push_back(token);
    }
    if(path[0]=='/'){
        Q.push_back("");
    }
    for(int i=0;i<tokens.size();i++){
        string token = tokens[i];
        if(token==".."){
            if(Q.empty() or Q.back()==".."){
                Q.push_back("..");
            }
            else if(Q.back()!=""){
                Q.pop_back();
            }
        }else{
            Q.push_back(token);
        }
    }
    if(Q.back()==""){
        return "/";
    }
    ostringstream oss;
    while(!Q.empty()){
        oss<<Q.front();
        Q.pop_front();
        if(!Q.empty()){
            oss<<"/";
        }
    }
    return oss.str();
}
int main(){
    string path;
    cin>>path;
    string simplified_path=simplifyPath(path);
    cout<<simplified_path;
    return 0;
}