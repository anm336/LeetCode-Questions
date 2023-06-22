class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>> &board){
        char val = board[i][j];
        
        for(int k=0;k<9;k++){
            //Check all in same column
            if(k!=i && board[k][j]==val) return false;
            
            //Check all in same column
            if(k!=j && board[i][k]==val) return false;
            
            //Check in same box
            int row = 3*(i/3)+k/3;
            int col = 3*(j/3)+k%3;
            if(row!=i && col!=j && board[row][col] == val){
                return false;
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.' && !isValid(i,j,board)) return false; 
            }
        }
        
        return true;
    }
};