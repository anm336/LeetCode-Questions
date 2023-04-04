class Solution {
public:
    int partitionString(string s) {
        unordered_map<int,int> mapping;
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            mapping[s[i] - 'a']++;
            if(mapping[s[i] - 'a']>1){
                ans++;
                mapping.clear();
                mapping[s[i]-'a']++;
            }
        }
        ans++;
        return ans;
    }
};