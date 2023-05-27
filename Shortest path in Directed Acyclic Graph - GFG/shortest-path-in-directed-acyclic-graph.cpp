//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     
     void dfs(int node, vector<pair<int,int>> graph[], stack<int> &stck, vector<int> &vis){
         vis[node] = true;
         
         for(auto neighbour: graph[node]){
             if(!vis[neighbour.first]) dfs(neighbour.first, graph, stck, vis);
         }
         
         stck.push(node);
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> graph[N];
        
        for(int i=0;i<M;i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        stack<int> stck;
        vector<int> vis(N, false);
        for(int i=0;i<N;i++){
            if(!vis[i]) dfs(i, graph, stck, vis);
        }
        
        vector<int> dist(N, INT_MAX);
        
        dist[0] = 0;
        
        while(!stck.empty()){
            int top = stck.top();
            stck.pop();
            
            if(dist[top] != INT_MAX){
                for(auto neighbour: graph[top]){
                    dist[neighbour.first] = min(dist[neighbour.first], dist[top] + neighbour.second);
                }
            }
            else dist[top] = -1;
            
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends