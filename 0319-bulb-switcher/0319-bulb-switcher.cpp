class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int x = sqrt(n);
        return floor(x);
    }
};