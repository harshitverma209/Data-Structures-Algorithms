/*The problem:
To calculate the number of ways in which 
a person can climb a ladder of N steps
if he can make a jump of 1,2, or 3 steps 
in one time*/
#include<iostream>
#include<vector>
using namespace std;
int countSteps(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return countSteps(n-1)+countSteps(n-2)+countSteps(n-3);
}
int main(){
    int n=10;
    int res=countSteps(n);
    cout<<res;
    return 0;
}