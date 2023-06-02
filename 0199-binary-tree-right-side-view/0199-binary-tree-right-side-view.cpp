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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        
        if(root == NULL) return ans;
        q.push(root);
        
        while(!q.empty()){
            int x = q.size();
            while(x>1){
                TreeNode* front = q.front();
                q.pop();
                if(front-> left != NULL) q.push(front-> left);
                if(front-> right != NULL) q.push(front-> right);
                x--;
            }
            TreeNode* front = q.front();
            q.pop();
            if(front-> left != NULL) q.push(front-> left);
            if(front-> right != NULL) q.push(front-> right);
            ans.push_back(front-> val);
        }
        
        return ans;
    }
};