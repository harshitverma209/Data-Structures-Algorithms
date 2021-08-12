/*The problem:
Given an unsorted array consisting of three types of balls(Red, Blue, Green),
the goal is to sort the array in linear time without using extra space.
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> sortBalls(vector<int> balls){
    int lo=0,hi=balls.size()-1,mid=0;
    while(mid<=hi){
        if(balls[mid]==0){
            swap(balls[lo++],balls[mid++]);
        }else if(balls[mid]==1){
            mid++;
        }
        else{
            swap(balls[mid],balls[hi--]);
        }
    }
    return balls;
}
int main(){
    vector<int> balls={2,0,1,2,0,1,2,0,1};
    balls=sortBalls(balls);
    for(int ball:balls){
        cout<<ball<<" ";
    }
    return 0;
}