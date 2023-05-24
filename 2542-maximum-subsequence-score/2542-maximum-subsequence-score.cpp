class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> nums;
        
        for(int i=0;i<n;i++){
            nums.push_back({nums2[i], nums1[i]});
        }
        
        sort(nums.rbegin(), nums.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        int minp = INT_MAX;
        long long sum = 0;
        
        while(i<k){
            pq.push(nums[i].second);
            sum+=nums[i].second;
            i++;
        }
        
        long long ans = 1LL*sum * nums[i-1].first;
        
        while(i<n){
            int x = pq.top();
            pq.pop();
            sum-=x;
            sum+=nums[i].second;
            pq.push(nums[i].second);
            ans = max(ans, 1LL*sum*nums[i].first);
            i++;
        }
        
        return ans;
    }
};