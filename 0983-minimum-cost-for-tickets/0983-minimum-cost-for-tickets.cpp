class Solution {
public:
    int func(int n,vector<int>& days, vector<int>& costs, int index, vector<int>& dp){
        if(dp[index]!=-1) return dp[index];
        else{
        if(index>=n){
            return 0;
        }
        
        int optn1 = costs[0] + func(n, days, costs, index+1, dp);
        
        int i;
        for(i=index;i<n && days[i]<days[index]+7; i++);
        int optn2 = costs[1] + func(n, days, costs, i, dp);
        
        for(i=index; i<n && days[i]<days[index]+30; i++);
        int optn3 = costs[2] + func(n, days, costs, i, dp);
        
        return dp[index] = min(optn1, min(optn2, optn3));
        }
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return func(n, days, costs, 0, dp);
    }
};