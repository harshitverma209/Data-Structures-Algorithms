#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compareBoxes(vector<int> box1, vector<int> box2){
    return box1[2]<box2[2];
}
bool canPlace(vector<int> box1, vector<int> box2){
    return box1[0]<box2[0] and box1[1]<box2[1] and box1[2]<box2[2];
}
int boxesStacking(vector<vector<int>> boxes,int N, int i, vector<int> &dp){
    //Base Case
    if(i==N-1){
        return dp[i]=boxes[i][2];
    }
    //Recursive Case
    if(dp[i]==0){
        int m=boxes[i][2];
        dp[i]=boxes[i][2];
        for(int j=i+1;j<N;j++){
            m=boxesStacking(boxes,N,j,dp)+boxes[i][2];
            if(canPlace(boxes[i],boxes[j])){
                dp[i]=max(dp[i],m);
            }
        }
    }
    return dp[i];
}

int main(){
    vector<vector<int>> boxes={ {2,1,2},
                                {3,2,3},
                                {2,2,8},
                                {2,3,4},
                                {2,2,1},
                                {4,4,5}
                            };
    int N=boxes.size();
    vector<int> dp(N,0);
    sort(boxes.begin(),boxes.end(),compareBoxes);
    boxesStacking(boxes,N,0,dp);
    int height=*max_element(dp.begin(),dp.end());
    cout<<height<<endl;
    return 0;
}