class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char, int> map1;
        
        for(int i=0;i<s.size();i++){
            map1[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;
        
        for(auto m: map1){
            pq.push({m.second, m.first});
        }
        
        while(pq.size()>1){
            char c1 = pq.top().second;
            int x1 = pq.top().first-1;
            
            pq.pop();
            
            char c2 = pq.top().second;
            int x2 = pq.top().first-1;
            
            pq.pop();
            
            ans+=c1;
            ans+=c2;
            
            if(x1>0) pq.push({x1, c1});
            if(x2>0) pq.push({x2, c2});
        }
        
        if(pq.size()>0){
            char c1 = pq.top().second;
            int x1 = pq.top().first;
            
            if(x1>1) return "";
            else ans+=c1;
        }
        
        return ans;
    }
};