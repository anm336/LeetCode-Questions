class Solution {
public:
    string removeStars(string s) {
        stack<char> stck;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!stck.empty()) stck.pop();
            }
            else{
                stck.push(s[i]);
            }
        }
        string ans;
        while(!stck.empty()){
            char x = stck.top();
            stck.pop();
            ans+=x;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};