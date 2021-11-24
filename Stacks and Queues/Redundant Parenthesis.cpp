#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isRedundant(string str){
    vector<char> op={'+', '-', '*', '%', '/'};
    stack<char> s;
    for(char c:str){
        if(c!=')'){
            s.push(c);
        }else{
            bool operator_found = false;
            while(!s.empty() && s.top() != '('){
                char top=s.top();
                if(find(op.begin(),op.end(),top)!=op.end()){
                    operator_found = true;
                }
                s.pop();
            }
            s.pop();
            if(!operator_found){
                return true;
            }
        }
    }
    return false;
}
bool isBalanced(string str){
    stack<char> s;
    for(char c:str){
        if(c=='('||c=='['||c=='{'){
            s.push(c);
        }else if(c==')'){
            if(!s.empty() && s.top()=='('){
                s.pop();
            }else{
                return false;
            }
        }else if(c==']'){
            if(!s.empty() && s.top()=='['){
                s.pop();
            }else{
                return false;
            }
        }else if(c=='}'){
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    return false;
}
int main(){
    stack<char> s;
    string str="(1+(2/3)+2+(3+3))";
    // cout<<isBalanced(str);
    cout<<isRedundant(str);
}