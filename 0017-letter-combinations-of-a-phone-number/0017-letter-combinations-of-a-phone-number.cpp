class Solution {
public:
    vector<string> ans;
    void func(string digits, int i, string &temp, unordered_map<int, string> &map){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int a=0; a<map[digits[i] - '0'].size(); a++){
            temp+=map[digits[i] - '0'][a];
            func(digits, i+1, temp, map);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits){
        if(digits.size() == 0) return ans;
        unordered_map<int,string> map;
        map[2]="abc";
        map[3]="def";
        map[4]="ghi";
        map[5]="jkl";
        map[6]="mno";
        map[7]="pqrs";
        map[8]="tuv";
        map[9]="wxyz";
        
        string temp = "";
        func(digits, 0, temp, map);
        
        return ans;
    }
};