class Solution {
public:
    bool dfs(int i, vector<vector<int>> &graph, vector<int> &status, vector<int> &ans, vector<bool> &inStack){
        if(graph[i].size() == 0){
            status[i] = 1;
            return true;
        }
        if(status[i]!=0){
            if(status[i]==1) return true;
            return false;
        }
        
        inStack[i] = true;
        bool val = true;
        for(auto x: graph[i]){
            if(!inStack[x] && dfs(x, graph, status, ans, inStack)){
                continue;
            }
            else{
                val = false;
                break;
            }
        }
        
        if(val==false) status[i] = -1;
        else status[i] = 1;
        
        inStack[i] = false;
        return val;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<int> status(n, 0);
        vector<bool> inStack(n, false);
        
        for(int i=0;i<n;i++){
            dfs(i, graph, status, ans, inStack);
        }
        
        for(int i=0;i<status.size();i++){
            if(status[i]==1) ans.push_back(i);
        }
        return ans;
    }
};