//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0;
        
        //To hold min. weights
        vector<int> key(V, INT_MAX);
        //To hold parent of node
        vector<int> par(V, -1);
        //To check if node included in mst
        vector<bool> mst(V, false);
        
        //Start from 0th
        key[0] = 0;
        par[0] = -1;
        
        //Do this V times to take every vertex in mst
        for(int i=0;i<V;i++){
            int mini = INT_MAX;
            int u;
            //Choose the node with min weight/key(not yet included in mst), that will be included in MST
            for(int j=0;j<V;j++){
                if(mst[j]==false && key[j]<mini){
                    mini = key[j];
                    u = j;
                }
            }
            
            //Mark it as true, now it's included in MST
            mst[u] = true;
            
            //Now, update min key for its neighbours, that are not yet included in mst
            for(auto neigh: adj[u]){
                int v = neigh[0];
                int w = neigh[1];
                
                if(mst[v]==false && w<key[v]){
                    key[v] = w;
                    par[v] = u;
                }
            }
        }
        
        for(auto x: key) ans+=x;
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends