#include<iostream>
#include<stack>
#include<string>
using namespace std;
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
    string str="(h(e)[l(lo)])";
    cout<<isBalanced(str);
}