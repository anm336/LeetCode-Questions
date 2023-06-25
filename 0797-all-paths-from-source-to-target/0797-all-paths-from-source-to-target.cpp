class Solution {
public:
    void func(vector<vector<int>> &graph, int src, int target, vector<int> temp, vector<vector<int>> &ans){
        if(src==target){
            ans.push_back(temp);
            return;
        }
        
        int node = src;
        for(int i=0;i<graph[node].size();i++){
            temp.push_back(graph[node][i]);
            func(graph, graph[node][i], target, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        
        vector<int> temp = {0};
        int n = graph.size();
        func(graph, 0 , n-1, temp, ans);
        
        return ans;
    }
};