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
    void func(TreeNode* root, int lvl, int &anslvl, int &ans){
        if(root == NULL) return;
        if(lvl>anslvl){
            anslvl = lvl;
            ans = root-> val;
        }
        if(root-> left) func(root-> left, lvl+1, anslvl, ans);
        if(root-> right) func(root-> right, lvl+1, anslvl, ans);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int ans = root-> val;
        int anslvl = 0;
        
        func(root, 0, anslvl, ans);
        
        return ans;
    }
};