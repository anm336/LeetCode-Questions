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
    void func(TreeNode* root, int maxtill, int &ans){
        if(root == NULL) return;
        if(root-> val >= maxtill){
            ans++;
            func(root-> left, root-> val, ans);
            func(root-> right, root-> val, ans);
        }
        else{
            func(root-> left, maxtill, ans);
            func(root-> right, maxtill, ans);
        }
    }
    
    int goodNodes(TreeNode* root) {
        if(!root-> left && !root-> right) return 1;
        
        int ans = 0;
        
        func(root, INT_MIN, ans);
        
        return ans;
    }
};