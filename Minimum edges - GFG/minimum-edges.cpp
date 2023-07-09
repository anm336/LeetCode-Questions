//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst){
            //Create a new modifir]=ed graph with edge weight, in it:
            //Add the given edge with weight 0 and reverse edge with weight 1.
            //Now find min distance using dijkstra and that will be answer.
            if(src==dst) return 0;
            vector<pair<int,int>> graph[n+1];
            for(auto x: edges){
                graph[x[0]].push_back({0, x[1]});
                graph[x[1]].push_back({1, x[0]});
            }
            
            set<pair<int, int>> s;
            vector<int> dist(n+1, INT_MAX);
            s.insert({0, src});
            
            while(!s.empty()){
                auto it = *(s.begin());
                s.erase(s.begin());
                
                for(auto neigh: graph[it.second]){
                    if(it.first + neigh.first < dist[neigh.second]){
                        auto finding = s.find({dist[neigh.second], neigh.second});
                        if(finding != s.end()){
                            s.erase({dist[neigh.second], neigh.second});
                        }
                        
                        dist[neigh.second] = it.first + neigh.first;
                        s.insert({it.first + neigh.first, neigh.second});
                    }
                }
            }
            
            return (dist[dst]!=INT_MAX) ? dist[dst]: -1;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends