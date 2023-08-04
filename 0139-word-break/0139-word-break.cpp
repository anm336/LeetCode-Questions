class Solution {
public:
    bool func(string A, unordered_map<string, int> &dict, unordered_map<string, bool> &dp){
        if(dict.find(A) != dict.end()) return true;
        
        if(dp.find(A) != dp.end()) return dp[A];
        bool ans = false;
        
        for(int j=1; j<A.size(); j++){
            string str = A.substr(0, j);
            //cout<<str<<endl;
            if(dict.find(str) != dict.end()){
                ans |= func(A.substr(j, A.size()-j), dict, dp);
                if(ans) break;
            }
        }
        
        return dp[A] = ans;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        
        unordered_map<string, int> dict;
        unordered_map<string, bool> dp;
        for(auto x: wordDict) dict[x]++;
        
        return func(s, dict, dp);
    }
};