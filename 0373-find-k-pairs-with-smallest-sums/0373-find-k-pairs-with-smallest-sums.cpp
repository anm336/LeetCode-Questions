class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        set<pair<int,int>> vis;
        
        pq.push({nums1[0]+nums2[0], 0, 0});
        vis.insert({0,0});
        
        while(k-- && pq.size()>0){
            auto vec = pq.top();
            pq.pop();
            int i = vec[1];
            int j = vec[2];
            
            ans.push_back({nums1[i], nums2[j]});
            
            if(i+1<n && vis.find({i+1, j}) == vis.end()){
                vis.insert({i+1, j});
                pq.push({nums1[i+1]+nums2[j], i+1, j});
            } 
            if(j+1<m && vis.find({i, j+1}) == vis.end()){
                vis.insert({i, j+1});
                pq.push({nums1[i]+nums2[j+1], i, j+1});
            } 
        }
        
        return ans;
    }
};