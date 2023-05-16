class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> mapping;
        
        for(int i=0;i<n;i++){
            int temp = arr[i] - difference;
            int val = 0;
            
            if(mapping.count(temp)) val+= mapping[temp];
            
            mapping[arr[i]] = 1+val;
            
            ans = max(ans, 1+val);
        }
        
        return ans;
    }
};