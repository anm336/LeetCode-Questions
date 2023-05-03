class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        for(int i=0;i<nums1.size();i++){
            map1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            map2[nums2[i]]++;
        }
        vector<vector<int>> ans;
        unordered_set<int> ans1;
        unordered_set<int> ans2;
        for(int i=0;i<nums1.size();i++){
            if(map2[nums1[i]]==0) ans1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(map1[nums2[i]]==0) ans2.insert(nums2[i]);
        }
        vector<int> anss1(ans1.begin(), ans1.end());
        vector<int> anss2(ans2.begin(), ans2.end());
        ans.push_back(anss1);
        ans.push_back(anss2);
        return ans;
    }
};