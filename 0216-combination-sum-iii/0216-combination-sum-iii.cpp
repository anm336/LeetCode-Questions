class Solution {
public:
    void func(int i, int k, int sum, vector<vector<int>> &ans, vector<int> temp){
        if(k<0 || sum<0) return;
        if(k==0 && sum==0){
            ans.push_back(temp);
        }
        
        for(int j=i+1;j<=9;j++){
            temp.push_back(j);
            func(j, k-1, sum-j, ans, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=1;i<=9;i++){
            temp.push_back(i);
            func(i, k-1, n-i, ans, temp);
            temp.pop_back();
        }
        
        return ans;
    }
};