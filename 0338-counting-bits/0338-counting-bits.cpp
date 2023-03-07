class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        if(n==0) return {0};
        if(n==1) return {0,1};
        if(n==2) return {0,1,1};
        ans.push_back(0);
        ans.push_back(1);
        ans.push_back(1);
        int power = 2;
        for(int i=3;i<=n;i++){
            if(i<pow(2, power)){
                ans.push_back(ans[i-pow(2, power-1)] + ans[pow(2, power-1)]);
            }
            else{
                ans.push_back(1);
                power++;
            }
        }
        return ans;
    }
};