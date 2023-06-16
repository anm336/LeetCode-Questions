class Solution {
public:
    vector<vector<string>> ans;
    
    bool valid(int row, int col, vector<string> &board){
        //column
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        
        //left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        
        //right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        
        return true;
    }
    
    void func(int i, int n, vector<string> &board){
        if(i==n){
            ans.push_back(board);
            return;
        }
        
        for(int j=0;j<n;j++){
            if(valid(i, j, board)){
                board[i][j] = 'Q';
                func(i+1, n, board);
                board[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        func(0, n, board);
        
        return ans;
    }
};