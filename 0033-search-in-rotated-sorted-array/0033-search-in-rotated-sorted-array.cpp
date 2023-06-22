class Solution {
public:
    int binsearch(int s, int e, vector<int> &nums, int target){
        int mid;
        while(s<=e){
            mid = (e-s)/2 + s;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
    
    int findPivot(vector<int> &nums){
        int s = 0;
        int e = nums.size()-1;
        int mid;
        
        while(s<e){
            mid = (e-s)/2 + s;
            if(nums[mid]>nums[0]) s = mid+1;
            else e = mid;
        }
        
        return s;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0]<nums[n-1]) return binsearch(0, n-1, nums, target);
        
        int p = findPivot(nums);
        cout<<p<<endl;
        
        if(target==nums[p]) return p;
        else if(target>=nums[0]) return binsearch(0, p-1, nums, target);
        return binsearch(p+1, n-1, nums, target);
    }
};