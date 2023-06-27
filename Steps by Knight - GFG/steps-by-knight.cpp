//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int steps = 0;
	    vector<pair<int, int>> dirs = {{-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}};
	    queue<pair<int,int>> q;
	    pair<int,int> start = {KnightPos[0], KnightPos[1]};
	    pair<int,int> target = {TargetPos[0], TargetPos[1]};
	    vector<vector<bool>> vis(N+1, vector<bool>(N+1, false));
	    
	    if(start == target) return steps;
	    q.push(start);
	    vis[start.first][start.second] = true;
	    bool found = false;
	    
	    while(!q.empty() && !found){
	        int x = q.size();
	        steps++;
	        while(x--){
	            auto pos = q.front();
	            q.pop();
	            int i = pos.first;
	            int j = pos.second;
	            
	            for(int k=0;k<dirs.size();k++){
	                int newi = i+dirs[k].first;
	                int newj = j+dirs[k].second;
	                
	                if(newi>0 && newi<=N && newj>0 && newj<=N){
	                    pair<int,int> newpos = {newi, newj};
	                    if(newpos == target){
	                        found = true;
	                        break;
	                    }
	                    else{
	                        if(!vis[newpos.first][newpos.second]){
	                            q.push(newpos);
	                            vis[newpos.first][newpos.second] = true;
	                        }
	                    }
	                }
	            }
	        }
	    }
	    
	    return steps;
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