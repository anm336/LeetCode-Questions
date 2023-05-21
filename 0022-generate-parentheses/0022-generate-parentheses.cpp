class Solution {
public:
    vector<string> ans;
    
    void func(int n, int fc, int bc, string temp){
        if(fc==n && bc==n){
            ans.push_back(temp);
            return;
        }
        
        if(fc<n) func(n, fc+1, bc, temp+"(");
        if(bc<fc) func(n, fc, bc+1, temp+")");
    }
    
    vector<string> generateParenthesis(int n) {
        func(n, 1, 0, "(");
        
        return ans;
    }
};