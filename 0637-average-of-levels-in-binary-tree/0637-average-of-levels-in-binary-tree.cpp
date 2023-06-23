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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int x = q.size();
            double n = x;
            double temp = 0;
            while(x--){
                TreeNode* front = q.front();
                q.pop();
                temp+=front-> val;
                if(front-> left) q.push(front-> left);
                if(front-> right) q.push(front-> right);
            }
            double avg = temp/n;
            ans.push_back(avg);
        }
        
        return ans;
    }
};