class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        if(maze[entrance[0]][entrance[1]] == '+') return -1;
        
        queue<pair<int,int>> q;
        vector<vector<int>> ans (n, vector<int> (m, -1));
        
        q.push({entrance[0], entrance[1]});
        ans[entrance[0]][entrance[1]] = 0;
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            
            if(!(x==entrance[0] && y==entrance[1]) && (x==0 || x==n-1 || y==0 || y==m-1)) return ans[x][y];
            if(maze[x][y] == '+') continue;
            
            maze[x][y] = '+';
            for(auto dir: dirs){
                int nx = x+dir[0];
                int ny = y+dir[1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny] == '.'){
                    ans[nx][ny] = 1 + ans[x][y];
                    q.push({nx,ny});
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return -1;
    }
};