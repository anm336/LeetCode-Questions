class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int i = 0;
        int j = n-1;
        int a = 0;
        int b = m-1;
        while(i<=j && a<=b){
            for(int k=a;k<=b;k++){
                ans.push_back(matrix[i][k]);
            }
            i++;
            for(int k=i;k<=j;k++){
                ans.push_back(matrix[k][b]);
            }
            b--;
            if(i<=j){
            for(int k=b;k>=a;k--){
                ans.push_back(matrix[j][k]);
            }
            j--;
            }
            if(a<=b){
            for(int k=j;k>=i;k--){
                ans.push_back(matrix[k][a]);
            }
            a++;
            }
        }
        return ans;
    }
};