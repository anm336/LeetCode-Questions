class Solution {
public:
    long long int reverse(int x) {
        long long int ans = 0;
        long long int y = abs(x);
        while(y>0){
            int rem = y%10;
            ans = ans*10 + rem;
            y/=10;
        }
        if(ans>pow(-2,31) && ans<pow(2,31)-1){
            if(x>=0) return ans;
            else return -ans;
        }
        else return 0;
    }
};