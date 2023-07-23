/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        
        if(n%2==0) return ans;
        
        if(n==1) return {new TreeNode()};
        
        if(mp.find(n) != mp.end()) return mp[n];
        
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> Left = allPossibleFBT(i);
            vector<TreeNode*> Right = allPossibleFBT(n-i-1);
            
            for(auto l: Left){
                for(auto r: Right){
                    ans.push_back(new TreeNode(0, l, r));
                }
            }
        }
        
        return mp[n] = ans;
    }
};