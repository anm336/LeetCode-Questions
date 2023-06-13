class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x = 0;
                while(x<n){
                    if(grid[x][i] != grid[j][x]) break;
                    x++;
                }
                if(x==n) ans++;
            }
        }
        
        return ans;
    }
};