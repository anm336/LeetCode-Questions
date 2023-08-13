class Solution {
public:
    bool isValid(int i, int j, vector<int> &arr){
        if(j-i+1 == 2){
            if(arr[i] == arr[j]) return true;
        }
        else if(j-i+1 == 3){
            if(arr[i] == arr[i+1] && arr[i+1] == arr[j]) return true;
            if(arr[i]+1 == arr[i+1] && arr[i+1]+1 == arr[j]) return true;
            return false;
        }
        
        return false;
    }
    
    bool func(int i, vector<int> &nums, vector<int> &dp){
        if(i==nums.size()) return true;
        
        if(dp[i] != -1) return dp[i];
        bool takeTwo = false;
        bool takeThree = false;
        
        int j = i+1;
        if(j<nums.size() && isValid(i, j, nums)) takeTwo |= func(i+2, nums, dp);
        j = i+2;
        if(j<nums.size() && isValid(i, j, nums)) takeThree |= func(i+3, nums, dp);
        
        return dp[i] = takeTwo || takeThree;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        return func(0, nums, dp);
    }
};