class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        
        int n = pairs.size();
        int end = pairs[0][1];
        int ans = 1;
        for(int i=1;i<n;i++){
            if(pairs[i][0]>end){
                ans++;
                end=pairs[i][1];
            }
        }
        
        return ans;
    }
};