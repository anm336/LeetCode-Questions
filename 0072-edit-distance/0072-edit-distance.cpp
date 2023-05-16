class Solution {
public:
    
    int func(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if(i==word1.size()) return word2.size()-j;
        if(j==word2.size()) return word1.size()-i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        //if both chars equal, move to both's next
        if(word1[i] == word2[j]) return dp[i][j] = func(word1, word2, i+1, j+1, dp);
        
        else{
            //w.r.t. first str
            //If insert character
            int insertAns = 1 + func(word1, word2, i, j+1, dp);
            //If delete character
            int deleteAns = 1 + func(word1, word2, i+1, j, dp);
            //If replace character
            int replaceAns = 1 + func(word1, word2, i+1, j+1, dp);
            
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        
        return dp[i][j] = ans;
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
        return func(word1, word2, 0, 0, dp);
    }
};