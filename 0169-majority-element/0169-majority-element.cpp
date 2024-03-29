class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ans;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt++;
                ans = nums[i];
            }
            else{
                if(nums[i]==ans) cnt++;
                else cnt--;
            }
        }
        
        return ans;
    }
};