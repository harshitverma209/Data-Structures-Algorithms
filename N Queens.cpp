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
bool solve_n_queens(int N,int i,vector<vector<int>> board){
    for(int j=0;j<N;j++){
        bool cp=canPlace(board,i,j);
        if(cp){
            board[i][j]=1;
            if(i==N-1){
                cout<<"Solution: "<<endl;
                for(auto v:board){
                    for(auto val:v){
                        cout<<val<<" ";
                    }
                    cout<<endl;
                }
                return true;
            }else{
                bool possible=solve_n_queens(N,i+1,board);
                if(possible){
                    return true;
                }else{
                    board[i][j]=0;
                }
            }
        }
    }
    return false;
}
int main(){
    int N=4;
    vector<vector<int>> board(N,vector<int>(N));
    
    bool possible=solve_n_queens(N,0,board);
    return 0;
}