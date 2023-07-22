//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool onBoard(int n, int x, int y){
        if(x>=n || y>=n || x<0 || y<0) return false;
        return true;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	    // Code here
	    if(KnightPos == TargetPos) return 0;
	    vector<vector<int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0], KnightPos[1]});
	    
	    vector<vector<bool>> vis(n+1, vector<bool> (n+1, false));
	    vis[KnightPos[0]][KnightPos[1]] = true;
	    
	    bool found = false;
	    int targetX = TargetPos[0];
	    int targetY = TargetPos[1];
	    int moves = 0;
	    
	    while(!q.empty() && !found){
	        int x = q.size();
	        moves++;
	        while(x--){
	            auto front = q.front();
	            q.pop();
	            int x = front.first;
	            int y = front.second;
	            for(int i=0;i<dirs.size();i++){
	                int newx = x+dirs[i][0];
	                int newy = y+dirs[i][1];
	                if(newx == targetX && newy == targetY){
	                    found = true;
	                    break;
	                }
	                if(onBoard(n, newx, newy) && !vis[newx][newy]){
	                    vis[newx][newy] = true;
	                    q.push({newx, newy});
	                }
	            }
	        }
	    }
	    
	    return moves;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends