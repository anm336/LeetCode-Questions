class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int mismatchs = 0;
        unordered_map<char, int> mp;
        
        int n = s.size();
        bool found = false;
        char schar, gchar; 
        
        for(int i=0;i<n;i++){
            if(mismatchs>2) return false;
            if(s[i]!=goal[i]){
                if(!found){
                    schar = s[i];
                    gchar = goal[i];
                    found = true;
                }
                else{
                    if(s[i]!=gchar || goal[i]!=schar) return false;
                }
                mismatchs++;
            }
            else mp[s[i]]++;
        }
        
        bool ans = false;
        if(mismatchs == 2) ans = true;
        if(mismatchs == 0){
            for(auto x: mp){
                if(x.second>1){
                    ans = true;
                    break;
                }
            }
        }
        
        return ans;
    }
};