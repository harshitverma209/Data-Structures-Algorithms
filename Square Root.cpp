/*The problem: To find the square root of a number N upto P decimal places
using Binary search*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
float sq_root(int n,int p){
    int beg=0,end=n,decimal_part=0;
    int mid=(beg+end)/2;
    while(beg<end){
        if(mid*mid<=n){
            decimal_part=max(mid,decimal_part);
            beg=mid+1;
        }
        else if(mid*mid>n){
            end=mid;
        }
        mid=(beg+end)/2;
    }
    //We now have the decimal part
    int d=1;
    float num=decimal_part;
    float inc=0.1;
    while(d<=p){
        for(int i=0;i<=9;i++){
            float a=num+inc;
            if(a*a>n){
                break;
            }
            num=a;
        }
        d++;
        inc/=10.0;
    }
    return num;
}
int main(){
    int n=10,p=3;
    float res=sq_root(n,p);
    cout<<res;
    return 0; 
}