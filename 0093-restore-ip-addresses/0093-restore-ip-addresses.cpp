class Solution {
public:
    bool isvalid(string s){
        if(s[0]=='0') return false;
        int myint = stoi(s);
        if(myint>255) return false;
            
        return true;
    }
    
    void func(string s, int i, int parts, string temp, vector<string> &ans){
        //cout<<temp<<endl;
        if(i==s.size() || parts == 4){
            if(s.size() == i && parts==4){
                ans.push_back(temp.substr(0, temp.size()-1));
            }
            return;
        }
        
        func(s, i+1, parts+1, temp+s[i]+".", ans);
        if(i+2<=s.size() && isvalid(s.substr(i, 2))){
            func(s, i+2, parts+1, temp+s.substr(i,2)+".", ans);
        }
        if(i+3<=s.size() && isvalid(s.substr(i, 3))){
            func(s, i+3, parts+1, temp+s.substr(i, 3)+".", ans);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size()>12) return ans;
        
        func(s, 0, 0, "", ans);
        
        return ans;
    }
};