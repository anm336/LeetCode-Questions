class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> freq;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        
        vector<vector<int>> ans;
        
        while(!freq.empty()){
            vector<int> temp;
            for(auto x: freq){
                temp.push_back(x.first);
            }
            for(auto elem: temp){
                if(!--freq[elem]) freq.erase(elem);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};