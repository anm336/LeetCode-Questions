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
    // vector<int> ans;
    // void preorder(TreeNode* root){
    //     if(root == NULL){
    //         return;
    //     }
    //     else{
    //         ans.push_back(root->val);
    //         preorder(root-> left);
    //         preorder(root-> right);
    //     }
    // }
    
    
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr-> left){
                TreeNode* prev = curr-> left;
                while(prev-> right){
                    prev = prev-> right;
                }
                prev-> right = curr-> right;
                curr-> right = curr-> left;
                curr-> left = NULL;
            }
            curr = curr-> right;
        }
        
        // if(root == NULL){
        //     return;
        // }
        // preorder(root);
        // TreeNode* head = new TreeNode();
        // head-> left = NULL;
        // TreeNode* temp = head;
        // for(int i=1;i<ans.size();i++){
        //     temp-> right = new TreeNode(ans[i]);
        //     temp-> left = NULL;
        //     temp = temp-> right;
        // }
        // root-> right = head-> right;
        // root-> left = NULL;
    }
};