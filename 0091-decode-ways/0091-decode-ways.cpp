class Solution {
public:
    int dp[101];
    int func(string& s, int i){
        if(i>=s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        int s1 = s[i] - '0', s2 = 0;
        if(i<s.size() - 1) s2 = s1*10 + s[i+1] - '0';
        if(s1>0) ans+= func(s, i+1);
        if(s1>0 && s2>0 && s2<27) ans+= func(s, i+2);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        memset (dp , -1 , sizeof dp);
        return func(s, 0);
    }
};