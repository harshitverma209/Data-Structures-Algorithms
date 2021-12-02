/*The problem:
The famous N-queens problem
*/
#include<iostream>
#include<vector>
using namespace std;
bool canPlace(vector<vector<int>> board, int row,int col){
    for(int i=0;i<board.size();i++){
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            if(abs(row-i)==abs(col-j) && board[i][j]==1){
                return false;
            }
        }
    }
    return true;
}
bool count_N_queens(int N,int i,vector<vector<int>> board, int &count){
    //Base Case
    if(i==N){
        if(N!=0){
            count++;
        };
        return false;
    }
    //Recursive Case
    for(int j=0;j<N;j++){
        bool cp=canPlace(board,i,k);
        if(cp){
            board[i][j]=1;
            bool possible=count_N_queens(N,i+1,board,count);
            if(possible){
                return true;
            }
                board[i][j]=0;
            
        }
    }
    return false;
}
int nQueen(int N){
    vector<vector<int>> board(N,vector<int>(N));
    int count=0;
    count_N_queens(N,0,board,count);
    return count;
}
int main(){
    int N=4;
    
    cout<<nQueen(N);
    return 0;
}