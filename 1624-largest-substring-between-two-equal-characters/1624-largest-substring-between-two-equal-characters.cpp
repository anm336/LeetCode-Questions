class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        
        int ans = -1;
        vector<vector<int>> occurs(26);
        for(int i=0;i<n;i++){
            occurs[s[i]-'a'].push_back(i);
        }
        
        for(auto vec: occurs){
            if(vec.size()<=1) continue;
            else{
                ans = max(ans, vec[vec.size()-1]-vec[0]-1);
            }
        }
        
        return ans;
    }
};