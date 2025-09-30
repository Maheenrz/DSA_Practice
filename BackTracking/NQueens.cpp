class Solution {
public:

    vector<vector<string>> results;

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        solve(0,board,n);
        return results;
        
    }

    void solve(int row,vector<string> &board,int n){
        if (row == n){
            results.push_back(board);
            return;
        }

        for(int i = 0; i < n ; i++){
            if(isSafe(row,i,board,n)){
                board[row][i]='Q';
                solve(row+1,board,n);
                board[row][i]='.';
            } 
        }

    }

    bool isSafe(int row,int col,vector<string> &board,int n){
        // check column conflict
        for(int i = 0; i < row; i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        // main diagonal conflict
        for(int i =0 ; row-i>=0 && col-i>=0 ;i++){
            if(board[row-i][col-i] == 'Q'){
            return false;
            }
        }
        // anti diagonal conflict
        for(int i =0 ; row-i>=0 && col+i>=0 ;i++){
            if(board[row-i][col+i] == 'Q'){
            return false;
            }
        }
        return true;
    }
};