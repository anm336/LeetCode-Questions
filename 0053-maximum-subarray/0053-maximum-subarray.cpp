class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int temp = nums[0];
        int ans = nums[0];
        for(int i=1;i<n;i++){
            ans = max(temp, ans);
            if(temp<0) temp=0;
            temp+=nums[i];
        }
        ans = max(ans, temp);
        if(ans<0){
            return *max_element(nums.begin(),nums.end());
        }
        else return ans;
    }
};