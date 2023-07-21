class Solution {
public:
    void prevSmall(vector<int> &heights, int n, vector<int> &prev){
        stack<int> s;
        s.push(-1);
        
        for(int i=0; i<n; i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]) s.pop();
            
            prev[i] = s.top();
            s.push(i);
        }
        
        return;
    }
    
    void nextSmall(vector<int> &heights, int n, vector<int> &next){
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]) s.pop();
            
            next[i] = s.top();
            s.push(i);
        }
        
        return;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n);
        vector<int> next(n);
        
        prevSmall(heights, n, prev);
        nextSmall(heights, n, next);
        
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            int Prev = prev[i];
            int Next = next[i];
            
            if(Next == -1) Next = n;
            
            int l = heights[i];
            int b = Next-Prev-1;
            
            ans = max(ans, l*b);
        }
        
        return ans;
    }
};