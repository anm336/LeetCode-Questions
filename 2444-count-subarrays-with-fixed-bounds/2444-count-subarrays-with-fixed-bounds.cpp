class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int tempmax = -1, tempmin = -1, tempbad = -1;
        for(int i=0;i<n;i++){
            if(nums[i]> maxK || nums[i]< minK) tempbad=i;
            if(nums[i]==maxK) tempmax = i;
            if(nums[i]==minK) tempmin = i;
            ans+=max(0, min(tempmax,tempmin) - tempbad);
        }
        return ans;
    }
};