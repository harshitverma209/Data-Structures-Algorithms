/*Given a matrix of 1's and 0's where 1 represents traversable path
(and 0 represents non-traversable blocked path),
find out the longest possible route from the top left to the bottom right.
You can not visit any location twice.
*/
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
void findLongestRoute(int i, int j,int m, int n, vector<vector<int>> mat, vector<int> currPath, vector<int> &longestPath){
    int eleCount=(i*n)+j+1;

    //Base Case
    if(i==m-1 && j==n-1){
        currPath.push_back(eleCount);
        // cout<<"SIZE: "<<currPath.size()<<endl;
        if(currPath.size()>longestPath.size()){
            longestPath=currPath;
        }
        // return;
    }

    //Recursive Case
    //Location already visited or not traversable
    if(!(mat[i][j] == 0 || find(currPath.begin(), currPath.end(),eleCount)!=currPath.end())){
        // cout<<"Adding: "<<eleCount<<endl;
        currPath.push_back(eleCount);
        //Go down
        if(i<m-1){
            // cout<<"Going Down"<<endl;
            findLongestRoute(i+1,j,m,n,mat,currPath,longestPath);
        }
        //Go up
        if(i>0){
            // cout<<"Going Up"<<endl;
            findLongestRoute(i-1,j,m,n,mat,currPath,longestPath);
        }
        //Go Right
        if(j<n-1){
            // cout<<"Going Right"<<endl;
            findLongestRoute(i,j+1,m,n,mat,currPath,longestPath);
        }
        if(j>0){
            // cout<<"Going Left"<<endl;
            findLongestRoute(i,j-1,m,n,mat,currPath,longestPath);
        }
        currPath.pop_back();

    }
}
vector<int> findLongestPath(int m, int n, vector<vector<int>> mat){
    vector<int> longestPath;
    findLongestRoute(0, 0, m, n, mat, {}, longestPath);
    return longestPath;
}
int main(){
    vector<vector<int> > mat={
        {1,1,1,1},
        {1,1,0,1},
        {0,0,0,1},
    };
    int m=mat.size(), n=mat[0].size();
    vector<int> route=findLongestPath(m,n,mat);
    for(auto l: route){
        cout<<l<<"\t";
    }
    return 0;
}