//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	static bool comp(vector<int> &A, vector<int> &B){
	    return A[2]<B[2];
	}
	
	void setpr(vector<int> &par, vector<int> &rank, int V){
	    for(int i=0;i<V;i++){
	        par[i] = i;
	        rank[i] = 0;
	    }
	}
	
	int findParent(int node, vector<int> &par){
	    if(par[node] == node) return node;
	    return par[node] = findParent(par[node], par);
	}
	
	void unionSet(int u, int v, vector<int> &par, vector<int> &rank){
	    if(rank[u]<rank[v]) par[u] = v;
	    else if(rank[v]<rank[u]) par[v] = u;
	    else{
	        //If equal
	        par[u] = v;
	        rank[v]++;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0;
        vector<int> par(V);
        vector<int> rank(V);
        vector<vector<int>> edges;
        
        setpr(par, rank, V);
        
        //Make edges
        for(int i=0;i<V;i++){
            vector<vector<int>> temp = adj[i];
            for(int j=0;j<temp.size();j++){
                vector<int> edge;
                edge.push_back(i);
                edge.push_back(temp[j][0]);
                edge.push_back(temp[j][1]);
                edges.push_back(edge);
            }
        }
        
        sort(edges.begin(), edges.end(), comp);
        
        for(int i=0;i<edges.size();i++){
            int u = findParent(edges[i][0], par);
            int v = findParent(edges[i][1], par);
            int w = edges[i][2];
            //cout<<u<<" "<<v<<" "<<w<<endl;
            
            if(u!=v){
                unionSet(u, v, par, rank);
                ans+=w;
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