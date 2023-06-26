class Solution {
public:
    void func(int i, vector<int> &nums, set<vector<int>> &ans){
        if(i==nums.size()){
            ans.insert(nums);
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            swap(nums[i], nums[j]);
            func(i+1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        
        func(0, nums, ans);
        vector<vector<int>> fans(ans.begin(), ans.end());
        return fans;
    }
};