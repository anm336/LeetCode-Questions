class Solution {
public:
    long long calccost(int target, vector<int> &nums, vector<int> &cost){
        long long costy = 0;
        
        for(int i=0;i<nums.size();i++){
            long long diff = abs(target-nums[i]);
            costy += 1LL*diff*cost[i];
        }
        
        return costy;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());
        long long ans = calccost(nums[0], nums, cost);
        
        while(s<e){
            int mid = (e-s)/2 + s;
            long long c1 = calccost(mid, nums, cost);
            long long c2 = calccost(mid+1, nums, cost);
            
            if(c1>c2){
                ans = c2;
                s = mid+1;
            }
            else{
                ans = c1;
                e = mid;
            }
         }
        
        return ans;
    }
};