class Solution {
public:
    bool valid(int row, int col, vector<vector<char>> &grid, char val){
        for(int i=0; i<9; i++){
            if(grid[i][col] == val){
                return false;
            }
            if(grid[row][i] == val){
                return false;
            }
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3] == val){
                return false;
            }
        }
        
        return true;
    }
    
    bool func(int i, int j, vector<vector<char>> &grid){
        if(i==9) return true;
        if(j==9) return func(i+1, 0, grid);
        
        if(grid[i][j]!='.'){
            return func(i, j+1, grid);
        }
        
        for(char k='1';k<='9';k++){
            if(valid(i, j, grid, k)){
                grid[i][j] = k;
                if(func(i, j+1, grid)) return true;
                grid[i][j] = '.';
            }
        }

        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        func(0, 0, board);
    }
};