class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        int n = haystack.size();
        int m = needle.size();
        if(m>n) return -1;
        for(int i=0;i<n-m+1;i++){
            string s = haystack.substr(i,m);
            if(s == needle){
                ans = i;
                break;
            }
        }
        return ans;
    }
};