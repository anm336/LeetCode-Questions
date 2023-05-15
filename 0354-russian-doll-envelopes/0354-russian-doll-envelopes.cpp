class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        int n = envelopes.size();
        
        //LIS
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=0;i<n;i++){
            if(envelopes[i][1]>ans.back()) ans.push_back(envelopes[i][1]);
            else{
                int ind = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[ind] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};