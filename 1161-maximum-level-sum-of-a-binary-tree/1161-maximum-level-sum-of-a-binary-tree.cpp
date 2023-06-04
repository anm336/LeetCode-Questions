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
    int maxLevelSum(TreeNode* root) {
        int sum = INT_MIN;
        int anslvl = 1;
        queue<TreeNode*> q;
        int lvl = 1;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            int temp = 0;
            while(x--){
                TreeNode* front = q.front();
                q.pop();
                temp+=front-> val;
                if(front-> left) q.push(front-> left);
                if(front-> right) q.push(front-> right);
            }
            if(temp > sum){
                sum = temp;
                anslvl = lvl;
            }
            lvl++;
        }
        
        return anslvl;
    }
};