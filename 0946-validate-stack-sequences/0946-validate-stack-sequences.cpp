class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> stck;
        int j=0;
        for(int i=0;i<n;i++){
            stck.push(pushed[i]);
            while(stck.size()>0 && stck.top() == popped[j]){
                stck.pop();
                j++;
            }
        }
        if(stck.empty()) return true;
        else return false;
    }
};