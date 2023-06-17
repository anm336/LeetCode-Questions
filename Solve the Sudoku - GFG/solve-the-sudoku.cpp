//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku.
    
    bool valid(int row, int col, int grid[N][N], int val){
        
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
    
    bool func(int i, int j, int grid[N][N]){
        if(i==9) return true;
        if(j==9) return func(i+1, 0, grid);
        
        if(grid[i][j]!=0){
            return func(i, j+1, grid);
        }
        
        for(int k=1;k<=9;k++){
            if(valid(i, j, grid, k)){
                grid[i][j] = k;
                if(func(i, j+1, grid)) return true;
                grid[i][j] = 0;
            }
        }

        return false;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return func(0, 0, grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends