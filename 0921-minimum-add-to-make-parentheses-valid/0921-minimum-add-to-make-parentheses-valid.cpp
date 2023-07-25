class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stck;
        int n = s.size();
        
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                stck.push('(');
            }
            else{
                if(!stck.empty() && stck.top()=='(') stck.pop();
                else stck.push(')');
            }
        }
        
        return stck.size();
    }
};