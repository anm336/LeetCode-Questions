class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int v = 0;
        vector<int> vc;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') v++;
            vc.push_back(v);
        }
        
        for(int i=0;i<=n-k;i++){
            int temp = vc[i+k-1] - vc[i];
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') temp++;
            
            ans = max(ans, temp);
        }
        
        return ans;
    }
};