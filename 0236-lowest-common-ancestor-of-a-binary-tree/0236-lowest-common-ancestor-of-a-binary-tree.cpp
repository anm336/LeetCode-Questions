/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool buildpath(TreeNode* root, vector<TreeNode*>& path, int x){
        if(root==NULL) return false;
        
        path.push_back(root);
        
        if(root-> val==x) return true;
        if(buildpath(root-> left, path, x) || buildpath(root-> right, path, x)) return true;
        
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        buildpath(root, path1, p-> val);
        buildpath(root, path2, q-> val);
        
        TreeNode* ans=path1[0];
        
        int m = path1.size();
        int n = path2.size();
        int i=0, j=0;
        
        while(i<m && j<n){
            if(path1[i]-> val != path2[j]-> val) break;
            else ans=path1[i];
            i++;
            j++;
        }
        
        return ans;
    }
};