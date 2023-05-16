class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int buy = prices[0];
        for(int i=1;i<n;i++){
            if(buy>prices[i]) buy = prices[i];
            else ans = max(ans, prices[i]-buy);
        }
        return ans;
    }
};