class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);
        
        int i=0, j=n-1, mid;
        
        while(i<=j){
            mid = (j-i)/2 + i;
            if(nums[mid]==target){
                ans[0] = mid;
                j = mid-1;
            }
            else if(nums[mid]>target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        
        i = 0;
        j = n-1;
        while(i<=j){
            mid = (j-i)/2 + i;
            if(nums[mid]==target){
                ans[1] = mid;
                i = mid+1;
            }
            else if(nums[mid]>target){
                j = mid-1;
            }
            else{
                i=mid+1;
            }
        }
        
        return ans;
    }
};