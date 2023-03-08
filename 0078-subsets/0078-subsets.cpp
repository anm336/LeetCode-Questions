class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void func(vector<int>& nums, int i){
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            func(nums, j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        func(nums, 0);
        return ans;
    }
};