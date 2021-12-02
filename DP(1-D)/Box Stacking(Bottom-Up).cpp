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
int boxesStacking(vector<vector<int>> boxes){
    int N=boxes.size();
    vector<int> dp(N,0);
    sort(boxes.begin(),boxes.end(),compareBoxes);
    dp[0]=boxes[0][2];
    for(int i=1;i<N;i++){
        dp[i]=boxes[i][2];
        for(int j=0;j<i;j++){
            if(canPlace(boxes[j],boxes[i])){
                dp[i]=max(dp[i],dp[j]+boxes[i][2]);
            }
        }
    }
    

    return *max_element(dp.begin(),dp.end());
}

int main(){
    vector<vector<int>> boxes={ {2,1,2},
                                {3,2,3},
                                {2,2,8},
                                {2,3,4},
                                {2,2,1},
                                {4,4,5}
                            };
    
    int height=boxesStacking(boxes);
    cout<<height<<endl;
    return 0;
}