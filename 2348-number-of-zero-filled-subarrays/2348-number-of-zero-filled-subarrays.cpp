class Solution {
public:
    long long ans = 0;
    void func(int x){
        long long y = 1LL*x*(x+1)/2;
        ans+=y;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int zers = 0;
        while(i<n){
            if(nums[i]==0){
                zers++;
            }
            else{
                if(zers>0) func(zers);
                zers=0;
            }
            i++;
        }
        if(zers>0) func(zers);
        return ans;
    }
};