class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> mapping;
        vector<int> ans;
        
        for(int i=0;i<edges.size();i++){
            mapping[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(mapping[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};