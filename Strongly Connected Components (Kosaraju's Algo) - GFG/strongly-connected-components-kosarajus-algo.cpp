//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topo(int node, vector<vector<int>> &adj, stack<int> &stck, vector<bool> &vis){
	    vis[node] = true;
	    for(auto neigh: adj[node]){
	        if(!vis[neigh]) topo(neigh, adj, stck, vis);
	    }
	    stck.push(node);
	}
	
	void dfs(int node, vector<int> radj[], vector<bool> &visi){
	    visi[node] = true;
	    for(auto neigh: radj[node]){
	        if(!visi[neigh]) dfs(neigh, radj, visi);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        int ans = 0;
        stack<int> stck;
        int n = V;
        vector<bool> vis(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i]) topo(i, adj, stck, vis);
        }
        
        vector<int> radj[n];
        // vector<vector<int>> radj(n);
        // for(int i = 0;i<n;i++){
        //     for(auto j : adj[i]){
        //         radj[j].push_back(i);
        //     }
        // }
        for(int i=0;i<n;i++){
            vector<int> temp = adj[i];
            int x = temp.size();
            for(int j=0;j<x;j++) radj[temp[j]].push_back(i);
        }
        
        vector<bool> visi(n, false);
        while(!stck.empty()){
            int node = stck.top();
            stck.pop();
            if(!visi[node]){
                dfs(node, radj, visi);
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends