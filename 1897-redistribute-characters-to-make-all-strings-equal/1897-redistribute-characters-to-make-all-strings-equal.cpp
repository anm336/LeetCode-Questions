class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        map<char, int> freq;
        
        for(int i=0;i<n;i++){
            for(auto x: words[i]){
                freq[x]++;
            }
        }
        
        for(auto x: freq){
            if(x.second%n!=0) return false;
        }
        
        return true;
    }
};