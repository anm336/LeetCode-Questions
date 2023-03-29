class Solution {
public:
    int func(vector<int>& satisfaction, int i, int n){
        int temp=0;
        int cnt = 1;
        for(int j=i;j<n;j++){
            temp+=cnt*satisfaction[j];
            cnt++;
        }
        return temp;
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,func(satisfaction, i, n));
        }
        return ans;
    }
};