class Solution {
public:
    int climbStairs(long long int n) {
        int x = 1;
        int y = 1;
        int temp;
        for(int i=1;i<n;i++){
            temp = x+y;
            x = y;
            y = temp;
        }
        return y;
    }
};