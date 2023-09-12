class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        
        unordered_map<char, int> freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        
        priority_queue<int> pq;
        for(auto x: freq){
            //cout<<x.second<<endl;
            pq.push(x.second);
        }
        
        int ans = 0;
        while(pq.size()>1){
            int top = pq.top();
            pq.pop();
            
            //cout<<top<<endl;
            if(pq.top() == top){
                ans++;
                if(top>1) pq.push(top-1);
            }
        }
        
        return ans;
    }
};