class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> bi(n, 0);
        
        for(int i=0;i<n;i++){
        if(bi[i] != 0) continue;
        else{
        queue<int> q;
        q.push(i);
        int x = 1;
        bi[i] = x;
        x = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
            int node = q.front();
            q.pop();
            for(int i=0;i<graph[node].size();i++){
                if(bi[graph[node][i]] == 0){
                    q.push(graph[node][i]);
                    bi[graph[node][i]] = x;
                }
                else{
                    if(bi[graph[node][i]] != x){
                        return false;
                        break;
                    }
                }
            }
            }
            if(x==1) x = -1;
            else x = 1;
        }
        }
        }
        return true;
    }
};