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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        ans.push_back(root-> val);
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int x = q.size();
            int largest = INT_MIN;
            while(x--){
                TreeNode* front = q.front();
                q.pop();
                if(front-> left){
                    largest = max(largest, front-> left-> val);
                    q.push(front-> left);
                }
                if(front-> right){
                    largest = max(largest, front-> right-> val);
                    q.push(front-> right);
                }
            }
            ans.push_back(largest);
        }
        ans.pop_back();
        
        return ans;
    }
};