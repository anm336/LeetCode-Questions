class Solution {
public:
    bool func(int i, int k, unordered_map<int, int> &pos, vector<int> &stones, int n, vector<vector<int>> &vis){
        if(i==n-1) return true;
        if(vis[i][k] != -1) return vis[i][k];
        
        bool ans = false;
        //k-1 jump
        if(k-1>0 && pos[stones[i]+k-1]!=0) ans|=func(pos[stones[i]+k-1], k-1, pos, stones, n, vis);
        //k jump
        if(pos[stones[i]+k]!=0) ans|=func(pos[stones[i]+k], k, pos, stones, n, vis);
        //k+1 jump
        if(pos[stones[i]+k+1]!=0) ans|=func(pos[stones[i]+k+1], k+1, pos, stones, n, vis);
        
        return vis[i][k] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> pos;
        
        for(int i=0;i<n;i++){
            pos[stones[i]] = i;
        }
        
        if(stones[1]!=1) return false;
        vector<vector<int>> vis(2001, vector<int> (2001, -1));
        
        return func(1, 1, pos, stones, n, vis);
    }
};