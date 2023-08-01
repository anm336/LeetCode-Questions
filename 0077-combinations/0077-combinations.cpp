class Solution {
public:
    void combinations(int ind, vector<vector<int>>& ans, vector<int>& temp, int n , int k, vector<int> nums){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(ind>=n){
            return;
        }
        for(int j=ind;j<n;j++){
            temp.push_back(nums[j]);
            combinations(j+1, ans, temp, n , k, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<int> temp;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        combinations(0, ans, temp, n, k, nums);
        return ans;
    }
};