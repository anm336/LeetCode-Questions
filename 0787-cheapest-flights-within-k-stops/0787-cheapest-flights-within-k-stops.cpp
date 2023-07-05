class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<pair<int,int>> graph[n];
        
//         for(int i=0;i<flights.size();i++) graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        for(int i=0;i<=k;i++){
            vector<int> temp(dist);
            for(int j=0;j<flights.size();j++){
                int u = flights[j][0];
                int v = flights[j][1];
                int w = flights[j][2];
                
                if(dist[u]!=1e9 && dist[u]+w < temp[v]) temp[v] = dist[u]+w;
            }
            dist = temp;
        }
        
        if(dist[dst] != 1e9) return dist[dst];
        return -1;
    }
};