class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        
        unordered_map<int,int> mp1, mp2;
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            mp1[A[i]]++;
            mp2[B[i]]++;
            
            if(A[i]==B[i]) cnt++;
            else{
                if(mp2[A[i]] > 0) cnt++;
                if(mp1[B[i]] > 0) cnt++;
            }
            ans[i] = cnt;
        }
        
        return ans;
    }
};