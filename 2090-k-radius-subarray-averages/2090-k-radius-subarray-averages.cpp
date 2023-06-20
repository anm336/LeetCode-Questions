class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        long long N = n;
        long long K = k;
        
        if(2*K+1 > N) return ans;
        long long sum = 0;
        
        for(int i=0;i<2*K+1;i++){
            sum+=nums[i];
        }
        
        ans[k] = sum/(2*K+1);
        for(int j=K+1;j<N-K;j++){
            sum-=nums[j-K-1];
            sum+=nums[j+K];
            ans[j] = sum/(2*K+1);
        }
        
        return ans;
    }
};