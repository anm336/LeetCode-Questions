class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        
        vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        while(!q.empty()){
            auto pt = q.front();
            q.pop();
            int x = pt.first;
            int y = pt.second;
            
            if(x==n-1 && y==n-1) return grid[x][y];
            
            for(auto dir: dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny] == 0){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx,ny});
                }
                
            }
        }
        
        return -1;
    }
};