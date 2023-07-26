class Solution {
public:
    int getMin(string &str){
        int n = str.size();
        
        stack<char> stck;
        for(int i=0;i<n;i++){
            if(str[i]=='(') stck.push(str[i]);
            else if(str[i] == ')'){
                if(!stck.empty() && stck.top() == '(') stck.pop();
                else stck.push(str[i]);
            }
        }
        
        return stck.size();
    }
    
    void func(string s, int mra, unordered_map<string, int> &mp, vector<string> &ans){
        if(mra == 0){
            int mrNow = getMin(s);
            if(mrNow == 0) ans.push_back(s);
            return;
        }
        
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] != ')' && s[i] != '(') continue;
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            if(mp.find(left+right) == mp.end()){
                mp[left+right]++;
                func(left+right, mra-1, mp, ans);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int mr = getMin(s);
        
        vector<string> ans;
        unordered_map<string, int> mp;
        
        func(s, mr, mp, ans);
        
        return ans;
    }
};