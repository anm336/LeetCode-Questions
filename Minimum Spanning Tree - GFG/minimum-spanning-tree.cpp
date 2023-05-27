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
        vector<int> wts(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> par(V, -1);
        
        //0 assumed as source;
        par[0] = -1;
        wts[0] = 0;
        
        for(int i=0;i<V;i++){
            //Get the minimum weight wali node
            int mini = INT_MAX;
            int u;
            
            for(int j=0;j<V;j++){
                if(mst[j]==false && wts[j]<mini){
                    mini = wts[j];
                    u = j;
                }
            }
            
            //Mark mst of it as true as, ab wo mst mei include ho jaegi
            mst[u] = true;
            
            //Check its adjacent Node
            for(auto neighbour: adj[u]){
                int nnode = neighbour[0];
                int wt = neighbour[1];
                
                if(mst[nnode] == false && wt < wts[nnode]){
                    //cout<<nnode<<" "<<wt<<endl;
                    wts[nnode] = wt;
                    par[nnode] = u;
                }
            }
        }
        
        
        int ans = 0;
        for(int i=0;i<V;i++){
            //cout<<wts[i]<<endl;
            ans+=wts[i];
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