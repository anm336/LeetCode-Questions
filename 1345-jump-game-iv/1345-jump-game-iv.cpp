class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mapping;
        for(int i=0;i<arr.size();i++){
            mapping[arr[i]].push_back(i);
        }
        int n = arr.size();
        
        vector<bool> vis(n, false);
        vis[0] = true;
        
        queue<int> q;
        q.push(0);
        int ans = 0;
        
        while(!q.empty()){
            int x = q.size();
            for(int i=0;i<x;i++){
                int ind = q.front();
                q.pop();
                if(ind == n-1) return ans;
                vector<int>& cantravelto = mapping[arr[ind]];
                if(ind > 0) cantravelto.push_back(ind-1);
                if(ind < n-1) cantravelto.push_back(ind+1);
                for(int j: cantravelto){
                    if(! vis[j]){
                        vis[j] = true;
                        q.push(j);
                    }
                }
                cantravelto.clear();
            }
            ans++;
        }
        
        return 0;
    }
};