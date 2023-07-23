class Solution {
public:
    vector<int> prevSmall(vector<int> &heights){
        vector<int> ans(heights.size());
        stack<int> s;
        s.push(-1);
        
        for(int i=0;i<heights.size();i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]) s.pop();
            
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }
    vector<int> nextSmall(vector<int> &heights){
        vector<int> ans(heights.size());
        stack<int> s;
        s.push(-1);
        
        for(int i=heights.size()-1;i>=0;i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]) s.pop();
            
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    int longestRectangle(vector<int> &heights){
        vector<int> prev = prevSmall(heights);
        vector<int> next = nextSmall(heights);
        
        int area = 0;
        for(int i=0;i<heights.size();i++){
            int Prev = prev[i];
            int Next = next[i];
            
            if(Next == -1) Next = heights.size();
            
            int l = heights[i];
            int b = Next-Prev-1;
            
            area = max(area, l*b);
        }
        
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mat(n, vector<int> (m, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '0') mat[i][j] = 0;
                else mat[i][j] = 1;
            }
        }
        vector<int> heights = mat[0];
        // for(int i=0;i<heights.size();i++) cout<<heights[i]<<" ";
        // cout<<endl;
        
        int ans = longestRectangle(heights);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) heights[j] = 0;
                else heights[j]+=mat[i][j];
            }
            ans = max(ans, longestRectangle(heights));
        }
        return ans;
        
        //return 0;
    }
};