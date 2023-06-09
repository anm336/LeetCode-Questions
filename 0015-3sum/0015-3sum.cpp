class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> tans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++){
            int target = -nums[i];
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int sum = nums[j] + nums[k];
                
                if(sum == target){
                    tans.insert({nums[i], nums[j], nums[k]});
                }
                if(sum>target) k--;
                else j++;
            }
        }
        
        vector<vector<int>> ans(tans.begin(), tans.end());
        
        return ans;
    }
};