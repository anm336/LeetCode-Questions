//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> graph[N];
        for(int i=0;i<M;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> vis(N, false);
        vector<int> par(N, INT_MAX);
        
        queue<int> q;
        q.push(src);
        vis[src] = true;
        par[src] = -1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto neighbour: graph[front]){
                if(!vis[neighbour]){
                    vis[neighbour] = true;
                    par[neighbour] = front;
                    q.push(neighbour);
                }
            }
            
        }
        
        vector<int> ans(N, -1);
        
        for(int i=0;i<N;i++){
            int x = par[i];
            if(x==INT_MAX) ans[i] = -1;
            else{
            int cnt = 0;
            
            while(x != -1){
                x = par[x];
                cnt++;
            }
            
            ans[i] = cnt;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends