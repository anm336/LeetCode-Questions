class Solution {
public:
    vector<string> ans;
    
    void func(int n, int fc, int bc, vector<vector<int>> &dp, string temp){
        if(fc==n && bc==n){
            ans.push_back(temp);
            return;
        }
        
        if(fc<n) func(n, fc+1, bc, dp, temp+"(");
        if(bc<fc) func(n, fc, bc+1, dp, temp+")");
    }
    
    vector<string> generateParenthesis(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        func(n, 1, 0, dp, "(");
        
        return ans;
    }
};