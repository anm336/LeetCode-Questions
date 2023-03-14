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
    void func(TreeNode* node, int& temp, int& ans){
        if(node-> left!= NULL){
            int x = temp*10 + node-> left -> val;
            func(node-> left, x, ans);
        }
        if(node-> right!= NULL){
            int x = temp*10 + node-> right -> val;
            func(node-> right, x, ans);
        }
        if(node-> left == NULL && node-> right == NULL){
            ans+=temp;
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        func(root, root-> val, ans);
        return ans;
    }
};