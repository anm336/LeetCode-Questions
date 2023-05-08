class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        for(int k=0;k<n;k++){
            ans+=mat[k][i++];
            ans+=mat[k][j--];
        }
        if(n%2!=0) ans-=mat[n/2][m/2];
        return ans;
    }
};