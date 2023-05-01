class Solution {
public:
    double average(vector<int>& salary) {
        int maxa = INT_MIN;
        int mina = INT_MAX;
        double sum = 0;
        int n = salary.size();
        for(int i=0;i<n;i++){
            sum+=salary[i];
            mina = min(mina, salary[i]);
            maxa = max(maxa, salary[i]);
        }
        sum-=maxa;
        sum-=mina;
        return sum/(n-2);
    }
};