class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            n = abs(n);
            x = 1/x;
        }
        if(n%2){
            return x*pow(x*x, n/2);
        }
        else{
            return pow(x*x, n/2);
        }
    }
};