class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        if(n==1) return nums[0];
        int j = n-1;
        int ans = INT_MAX;
        
        if (nums[j] > nums[0]) {
            return nums[0];
        }
        
        while(i<=j){
            int mid = (j-i)/2 + i;
            
            if(nums[mid+1] < nums[mid]){
                ans = nums[mid+1];
                break;
            }
            if(nums[mid-1] > nums[mid]){
                ans = nums[mid];
                break;
            }
            
            if(nums[mid] > nums[0]) i = mid+1;
            else j = mid - 1;
        }
        
        return ans;
    }
};