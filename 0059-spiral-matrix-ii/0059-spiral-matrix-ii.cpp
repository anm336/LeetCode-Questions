class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sq = n*n;
        vector<vector<int>> ans(n, vector<int> (n, 0));
        int i = 1;
        int a = 0;
        int b = n-1;
        int p = 0;
        int q = n-1;
        while(i<=sq && a<=b && p<=q){
            for(int k=p;k<=q;k++){
                ans[a][k] = i;
                i++;
            }
            a++;
            for(int k=a;k<=b;k++){
                ans[k][q] = i;
                i++;
            }
            q--;
            if(a<=b){
            for(int k=q;k>=p;k--){
                ans[b][k] = i;
                i++;
            }
            b--;}
            if(p<=q){
            for(int k=b;k>=a;k--){
                ans[k][p] = i;
                i++;
            }
            p++;}
        }
        return ans;
    }
};