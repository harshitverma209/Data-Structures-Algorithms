/*The problem:
Find the path from the top left to the bottom right of a 2D matrix.
You can only move down or to the right. You can not move to the blocked parts of the matrix('X')
*/
#include<iostream>
#include<vector>
using namespace std;
bool solve_maze(int N, vector<vector<char>> maze, int i, int j, vector<int> &path){
    int eleIndex=i*N+j+1;
    //Base Case(Destination reached)
    if(i==N-1 && j==N-1){
        path.push_back(eleIndex);
        return true;
    }
    //Recursive Case(Can Move)
    if(i+1<N && maze[i+1][j]=='O'){
        path.push_back(eleIndex);
        return solve_maze(N,maze,i+1,j,path);
        path.pop_back();
    }
    if(j+1<N && maze[i][j+1]=='O'){
        path.push_back(eleIndex);
        return solve_maze(N,maze,i,j+1,path);
        path.pop_back();
    }
    return false;
}
vector<int> findPath(int N, vector<vector<char>> maze){
    vector<int> path;
    solve_maze(N,maze,0,0,path);
    return path;
}
int main(){
    vector<vector<char>> maze={
    {'O','O','X','O'},
    {'O','X','O','O'},
    {'O','O','O','X'},
    {'X','X','O','O'}
    };
    int N=maze.size();
    vector<int> path=findPath(N,maze);
    for(auto r : path){
        cout<<r<<"\t";
    }
    return 0;
}