class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0 || s.empty()) {
                s.push(asteroids[i]);
            }
            else {
                while(!s.empty() && s.top() > 0 && s.top() < abs(asteroids[i])) {
                    s.pop();
                }
                if(!s.empty() && s.top() == abs(asteroids[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(asteroids[i]);
                    }
                }
            }
        }
        
        vector<int> ans;
        while(!s.empty()){
            int x = s.top();
            s.pop();
            ans.push_back(x);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};