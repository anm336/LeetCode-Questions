class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int l = 0;
        int h = nums.size() - 1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            else if(nums[mid]>target){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};