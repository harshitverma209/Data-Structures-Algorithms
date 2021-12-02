/*The problem:
Give a partially filled sudoku board,
fill it according to the sudoku rules.
*/
#include<iostream>
#include<vector>
using namespace std;
bool canPlace(vector<vector<int>> mat, int val, int row,int col){
    //Check Column
    for(int i = 0; i < mat.size();i++){
        if(mat[i][col]==val){
            return false;
        }
    }
    //Check Row
    for(int j = 0; j<mat.size(); j++){
        if(mat[row][j]==val){
            return false;
        }
    }
    //Check Subgrid
    //9 Total Subgrids
    row=(row/3)*3;
    col=(col/3)*3;
    for(int i=row;i<row+3;i++){
        for(int j=col;j<col+3;j++){
            if(mat[i][j]==val){
                return false;
            }
        }
    }
    return true;
}
bool solve_sudoku(vector<vector<int>> &mat,int i,int j,int N){
    //Base Case
    if(i==N){
        cout<<"Solution: "<<endl;
        for(auto v:mat){
            for(auto val:v){
                cout<<val<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    //Recursive Case
    if(j==N){
        return solve_sudoku(mat,i+1,0,N);
    }

    //Don't touch already filled cells
    if(mat[i][j]!=0){
        return solve_sudoku(mat,i,j+1,N);
    }
    
    for(int k=1;k<=N;k++){
        if(canPlace(mat,k,i,j)){
            mat[i][j]=k;
            bool solvable = solve_sudoku(mat,i,j+1,N);
            if(solvable){
                return true;
            }
        }
    }
    mat[i][j]=0;
    return false;
}
int main(){
    int N=9;
    vector<vector<int>> mat(N,vector<int>(N));
    mat={
        {0,3,0,0,0,0,9,0,0},
        {0,0,6,0,0,0,0,0,0},
        {0,0,0,2,4,1,0,3,0},
        {0,0,0,9,0,0,7,0,0},
        {0,0,0,0,0,2,0,0,4},
        {0,8,0,0,7,0,0,2,0},
        {8,5,0,0,0,0,0,0,0},
        {0,9,0,7,0,4,0,0,0},
        {0,0,0,0,0,6,0,0,1}
        };
    bool solvable=solve_sudoku(mat,0,0,N);

    return 0;
}