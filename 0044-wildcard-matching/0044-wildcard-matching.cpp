class Solution {
public:
    
    bool func(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        
        //Base Cases
        //If both consumed as whole
        if(i<0 && j<0) return true;
        
        //If pattern fully used but string still remains
        if(i>=0 && j<0) return false;
        
        //If string finished but pattern remain, true only if stars remain(as they can be replace with empty string also).
        if(j>=0 && i<0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = func(s, p, i-1, j-1, dp);
        }
        else if(p[j] == '*'){
            //Two cases either replace * as empty string ,in which case reduce pattern's index) or else use a character to match string's char and reduce string's index while pattern index remain same for further usage or to be replaced as empty string finally.
            return dp[i][j] = func(s, p, i, j-1, dp) || func(s, p, i-1, j, dp);
        }
        else return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        return func(s, p, n-1, m-1, dp);
    }
};