class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        
        while(s<e){
            int mid = (e-s)/2 + s;
    
            if(nums[mid]<nums[mid+1]) s=mid+1;
            else e = mid;
            
        }
        
        return s;
    }
};