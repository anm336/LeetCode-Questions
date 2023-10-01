class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";
        int l = 0;
        for(int i=0;i<n;i++){
            if(s[i]==' ' || i==n-1){
                if(i!=n-1){
                int nd = i-1;
                int st = nd-l+1;
                while(st<nd){
                    char x = s[st];
                    s[st] = s[nd];
                    s[nd] = x;
                    st++;
                    nd--;
                }
                l = 0;
                temp = "";
                }
                else{
                    int nd = n-1;
                    int st = nd-l;
                    while(st<nd){
                    char x = s[st];
                    s[st] = s[nd];
                    s[nd] = x;
                    st++;
                    nd--;
                }
                }
            }
            else{
                temp+=s[i];
                l++;
            }
        }
        return s;
    }
};