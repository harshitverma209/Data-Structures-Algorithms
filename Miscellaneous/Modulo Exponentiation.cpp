/*The problem:
To calculate (a^b)%modulo.
*/
#include<iostream>
using namespace std;
long int calc_modulo_exponential(int a, int b, long modulo){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a%modulo;
    }
    return a*calc_modulo_exponential(a, b-1, modulo)%modulo;
}
int main(){
    int a=500, b=300;
    long int modulo=1000000007;
    long int res=calc_modulo_exponential(a,b,modulo);
    cout<<res<<endl;
    return 0;
}