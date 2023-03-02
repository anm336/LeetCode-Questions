class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int temp = 1;
        char prevChar = chars[0];
        string s;
        for(int i=1;i<n;i++){
            if(chars[i]==prevChar){
                temp++;
            }
            else{
                if(temp==1){
                    s+=prevChar;
                    prevChar=chars[i];
                }
                else{
                    s+=prevChar;
                    s+=to_string(temp);
                    prevChar=chars[i];
                    temp=1;
                }
            }
        }
        if(temp==1){
            s+=prevChar;
        }
        else{
            s+=prevChar;
            s+=to_string(temp);
        }
        for(int i=0;i<s.size();i++){
            chars[i] = s[i];
        }
        if(n>s.size()){
            int x = n-s.size();
            while(x>0){
                chars.pop_back();
                x--;
            }
        }
        return s.size();
    }
};