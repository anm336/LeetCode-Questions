class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0, ans = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(auto x: bank[i]){
                if(x=='1') cnt++;
            }
            
            if(cnt>0){
                ans+=(prev*cnt);
                prev = cnt;
            }
        }
        
        return ans;
    }
};