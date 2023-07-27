class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = accumulate(batteries.begin(), batteries.end(), (long long)0);
        
        long long lo = (long long)1;
        long long hi = (long long)sum/n;
        
        while(lo<hi){
            long long mid = hi - (hi - lo)/2;
            
            long long extra = 0;
            for(auto power: batteries){
                extra += min((long long)power, mid);
            }
            
            if(extra >= (long long)n*mid) lo = mid;
            else hi = mid-1;
        }
        
        return lo;
    }
};