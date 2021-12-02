#include<iostream>
#include<unordered_set>
using namespace std;
char firstRepeatChar(string str){
    unordered_set<char> charset;
    for(char c:str){
        if(charset.find(c) != charset.end()){
            return c;
        }
        else{
            charset.insert(c);
        }
    }
}
int main(){
    string str="codingminutes";
    char c=firstRepeatChar(str);
    cout<<c;
    return 0;
}