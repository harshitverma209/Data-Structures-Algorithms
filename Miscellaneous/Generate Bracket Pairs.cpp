/*The problem:
To generate all possible combinations of valid
brackets given the max number of bracket pairs 'N'
*/
#include<iostream>
using namespace std;

void generate_brackets(string s,int n, int open, int closed){
    if(open==n && closed==open){
        cout<<s<<endl;
        return;
    }
    if(open<n){
        generate_brackets(s+"(",n,open+1,closed);
    }
    if(closed<open){
        generate_brackets(s+")",n,open,closed+1);
    }

}
int main(){
    int n=3;
    generate_brackets("",n,0,0);
    return 0;
}