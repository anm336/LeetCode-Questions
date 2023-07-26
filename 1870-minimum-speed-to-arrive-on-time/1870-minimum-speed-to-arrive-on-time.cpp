class Solution {
public:
    double calcTime(vector<int> &dist, int speed){
        double ans = 0;
        int n = dist.size();
        
        for(int i=0;i<n-1;i++){
            int temp = ceil((1.0*dist[i])/speed);
            ans+=temp;
        }
        
        double t = (1.0*dist[n-1])/speed;
        ans+=t;
        
        //cout<<speed<<" "<<ans<<endl;
        return ans;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = -1;
        
        int lo = 1, hi = 1e7;
        while(lo<=hi){
            int mid = (hi-lo)/2 + lo;
            double time = calcTime(dist, mid);
            if(time<=hour){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        
        return ans;
    }
};