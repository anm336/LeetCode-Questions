class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x = *min_element(nums.begin(), nums.end());
        int ans = accumulate(nums.begin(), nums.end(), 0);
        ans-=x*nums.size();
        return ans;
    }
};