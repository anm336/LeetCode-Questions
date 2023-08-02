//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0 || A[X][Y] == 0) return -1;
        vector<vector<bool>> vis(N, vector<bool> (M, false));
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        bool found = false;
        int steps = 0;
        if(X==0 && Y==0) return 0;
        
        while(!q.empty() && !found){
            steps++;
            int x = q.size();
            while(x-- && !found){
                auto front = q.front();
                q.pop();
                for(auto dir: dirs){
                    int newx = front.first+dir[0];
                    int newy = front.second+dir[1];
                    
                    if(newx==X && newy==Y){
                        found = true;
                        break;
                    }
                    if(newx>=0 && newx<N && newy>=0 && newy<M && A[newx][newy]==1 && !vis[newx][newy]){
                        q.push({newx, newy});
                        vis[newx][newy] = true;
                    }
                }
            }
        }
        
        if(!found) return -1;
        return steps;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends