class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mapping;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mapping[temp].push_back(strs[i]);
        }
        for(auto it: mapping){
            ans.push_back(it.second);
        }
        return ans;
    }
};