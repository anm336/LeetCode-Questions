class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = INT_MIN;
        vector<int> adj[n];
        queue<pair<int, int>> q;
        
        for(int i=0;i<n;i++){
            if(manager[i] == -1) continue;
            adj[manager[i]].push_back(i);
        }
        
        q.push({headID, 0});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int parent = front.first;
            int time = front.second;
            
            ans = max(ans, time);
            
            for(auto neigh: adj[parent]){
                q.push({neigh, time+informTime[parent]});
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
    }
};