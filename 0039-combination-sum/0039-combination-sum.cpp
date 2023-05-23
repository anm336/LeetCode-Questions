class Solution {
public:
    vector<int> temp;
    void func(vector<int> &candidates, vector<vector<int>> &ans, int target, vector<int> &dp){
        if(target==0){
            multiset<int> s1(temp.begin(), temp.end());
            vector<int> t(s1.begin(), s1.end());
            ans.push_back(t);
            return;
        }
        
        for(int i=0;i<candidates.size();i++){
            if(target-candidates[i] >= 0){
                temp.push_back(candidates[i]);
                func(candidates, ans, target-candidates[i], dp);
                temp.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> dp(target+1, -1);
        
        func(candidates, ans, target, dp);
        
        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> fans(s.begin(), s.end());
        return fans;
    }
};