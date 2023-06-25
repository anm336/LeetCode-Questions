#define mod 1000000007

class Solution {
public:
    int func(vector<int> &locations, int start, int finish, int fuel, int n, vector<vector<int>> &dp){
        int temp = 0;
        //One case has occured
        if(start==finish) temp = 1;
        
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        
        for(int i=0;i<n;i++){
            if(start!=i){
                int fuelreq = abs(locations[start]-locations[i]);
                if(fuelreq<=fuel){
                    temp = (temp+func(locations, i, finish, fuel-fuelreq, n, dp))%mod;
                }
            }
        }
        
        return dp[start][fuel] = temp;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n+1, vector<int> (fuel+1, -1));
        
        func(locations, start, finish, fuel, n, dp);
        return dp[start][fuel]%mod;
    }
};