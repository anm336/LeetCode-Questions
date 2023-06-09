class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind1 = -1, ind2;
        int i = n-1;
        while(i>0){
            if(nums[i-1]<nums[i]){
                ind1 = i-1;
                break;
            }
            i--;
        }
        
        if(ind1 == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int x = nums[ind1];
        i = n-1;
        while(i>0){
            if(nums[i] > x){
                ind2 = i;
                break;
            }
            i--;
        }
        
        swap(nums[ind1], nums[ind2]);
        
        reverse(nums.begin() + ind1 + 1, nums.end());
    }
};