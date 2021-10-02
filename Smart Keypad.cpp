/*The problem:
Given an input from the numeric keypad of a modern day smartphone,
generate all possible combinations of characters present on the respective keys.
*/
#include<iostream>
#include<vector>
using namespace std;
string keypad[]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void generate_suggestions(string str, string output, int n,int i){
    if(i==n){
        cout<<output<<endl;
        return;
    }
    int digit=str[i]-'0';
    string chars=keypad[digit];
    if(!chars.length()){
        generate_suggestions(str,output,n,i+1);
    }
    for(int j=0;j<chars.length();j++){
        generate_suggestions(str,output+chars[j],n,i+1);
    }
}
int main(){
    string inputString="26261276";
    int n=inputString.length();
    generate_suggestions(inputString, "", n,0);
    return 0;
}