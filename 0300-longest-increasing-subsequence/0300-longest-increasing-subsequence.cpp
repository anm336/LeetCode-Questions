class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()) ans.push_back(nums[i]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i]; 
            }
        }
        return ans.size();
    }
    
    int lis(int input1, int input2[]){
        int n = input1;
        if(n==0) return 0;
        
        vector<int> ans;
        ans.push_back(input2[0]);
        for(int i=1;i<n;i++){
            if(input2[i]>ans.back()) ans.push_back(input2[i]);
            else{
                int index = lower_bound(ans.begin(), ans.end(), input2[i]) - ans.begin();
                ans[index] = input2[i]; 
            }
        }
        return ans.size();
    }
};