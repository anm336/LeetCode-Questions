class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> occur;
        for(auto x: nums1){
            if(occur[x] == 0) occur[x]++;
        }
        
        for(auto x: nums2){
            if(occur[x] != 0){
                ans.push_back(x);
                occur[x]--;
            }
        }
        
        return ans;
    }
};