class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        
        int tc=0;
        int fc=0;
        int start=0;
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            if(answerKey[i]=='T') tc++;
            else fc++;
            
            while(fc>k && tc>k){
                if(answerKey[start] == 'T') tc--;
                else fc--;
                start++;
            }
            
            ans = max(ans, i-start+1);
        }
        
        return ans;
    }
};