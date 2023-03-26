class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mapping[nums[i]]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto[key, value]: mapping){
            pq.push({value, key});
        }
        
        while(k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};