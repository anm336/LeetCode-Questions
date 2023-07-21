class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> suf(n, 1);
        
        int temp = 1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp*=nums[i];
                pre[i] = temp;
            }
            else temp = 1, pre[i]=0;
        }
        temp = 1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=0){
                temp*=nums[i];
                suf[i] = temp;
            }
            else temp = 1, suf[i]=0;
        }
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans, max(pre[i], suf[i]));
        }
        
        return ans;
    }
};