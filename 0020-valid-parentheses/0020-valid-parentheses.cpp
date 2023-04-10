class Solution {
public:
    bool isValid(string s) {
        vector<char> opening = {'(','{','['};
        vector<char> closing = {')','}',']'};
        stack<char> stck;
        for(int i=0; i<s.length() ;i++){
            if (find(opening.begin(), opening.end(), s[i]) != opening.end()){
                stck.push(s[i]);
            } 
            else if (find(closing.begin(), closing.end(), s[i]) != closing.end()){
                auto it = find(closing.begin(), closing.end(), s[i]);
                int x = it - closing.begin();
                if(!stck.empty()){
                    if(stck.top() == opening[x]){
                        stck.pop();
                    }
                    else{
                        return false;
                        break;
                    }
                }
                else{
                    return false;
                    break;
                }
                
            }
        }
        if(!stck.empty()){
            return false;
        }
        else{
            return true;
        }
    }
};