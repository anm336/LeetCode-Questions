class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> ans(n);
        
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = nums[i]+prefix[i-1];
        }
        
        ans[0] = prefix[n-1]-n*nums[0];
        for(int i=1;i<n;i++){
            int temp = 0;
            temp += (i*nums[i]-prefix[i-1]);
            temp += (prefix[n-1]-prefix[i-1]-(n-i)*nums[i]);
            ans[i] = temp;
        }
        
        return ans;
    }
};