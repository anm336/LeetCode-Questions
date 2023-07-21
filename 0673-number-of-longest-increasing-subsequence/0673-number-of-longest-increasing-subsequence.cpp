class Solution {
public:
//     bool func(int i, int last, vector<int> &nums, int size, vector<vector<int>> &dp, int &ans){
//         if(i==nums.size()){
//             if(size==0) ans++, return true;
//             return;
//         }
        
//         if(last==-1 || nums[i]>nums[last]){
//             func(i+1, i, nums, size-1, dp, ans);
//         }
//         func(i+1, last, nums, size, dp, ans);
        
//         return;
//     }
    
    int findNumberOfLIS(vector<int>& nums) {
//         vector<int> lis;
//         int n = nums.size();
//         lis.push_back(nums[0]);
        
//         for(int i=1;i<n;i++){
//             if(nums[i]>lis.back()) lis.push_back(nums[i]);
//             else{
//                 int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
//                 lis[ind] = nums[i];
//             }
//         }
        
//         int longest = lis.size();
        
//         int ans = 0;
        
//         vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
//         func(0, -1, nums, longest, dp, ans);
        
//         return ans;
        
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLength = *max_element(length.begin(), length.end());
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                ans += count[i];
            }
        }

        return ans;
    }
};