class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1) return (grid[0][0] < 0) ? 1: 0;
        int i=0, j = m-1;
        int upto = 0;
        while(i<n && j>=0){
            if(grid[i][j] < 0){
                upto++;
                j--;
            }
            else{
                ans+=upto;
                i++;
            }
        }
        
        ans+=upto*(n-i);
        
        return ans;
    }
};