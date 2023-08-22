class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        
        long long int colNum = 1LL*columnNumber;
        while(colNum>0){
            colNum--;
            ans+=(char)(colNum%26+'A');
            colNum/=26;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};