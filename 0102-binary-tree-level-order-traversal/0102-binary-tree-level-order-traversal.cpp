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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root-> val});
        while(!q.empty()){
            vector<int> tempvec;
            int x = q.size();
            while(x){
                TreeNode* temp = q.front();
                q.pop();
                if(temp-> left!=NULL){
                    q.push(temp-> left);
                    tempvec.push_back(temp-> left-> val);
                }
                if(temp-> right!=NULL){
                    q.push(temp-> right);
                    tempvec.push_back(temp-> right-> val);
                }
                x--;
            }
            if(tempvec.size()>0) ans.push_back(tempvec);
            tempvec.empty();
        }
        return ans;
    }
};