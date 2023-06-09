class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> tans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == 0){
                    tans.insert({nums[i], nums[j], nums[k]});
                }
                if(sum>0) k--;
                else j++;
            }
        }
        
        vector<vector<int>> ans(tans.begin(), tans.end());
        
        return ans;
    }
};