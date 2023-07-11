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
    void makeGraph(TreeNode* root,unordered_map<int, vector<int>> &graph){
        if(root==NULL) return;
        
        if(root-> left){
            graph[root-> val].push_back(root-> left-> val);
            graph[root-> left-> val].push_back(root-> val);
            
            makeGraph(root-> left, graph);
        }
        if(root-> right){
            graph[root-> val].push_back(root-> right-> val);
            graph[root-> right-> val].push_back(root-> val);
            
            makeGraph(root-> right, graph);
        }
        
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target-> val};
        vector<int> ans;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> vis; 
        
        makeGraph(root, graph);
        // for(auto temp: graph){
        //     cout<<temp.first<<":";
        //     for(auto x: temp.second) cout<<x<<" ";
        //     cout<<endl;
        // }
        int cnt = 0;
        queue<int> q;
        q.push(target-> val);
        
        while(!q.empty()){
            cnt++;
            if(cnt==k){
                int x = q.size();
                while(x--){
                    int front = q.front();  
                    q.pop();
                    for(auto neigh: graph[front]){
                        if(!vis[neigh]) ans.push_back(neigh);
                    }
                }
                break;
            }
            else{
                int x = q.size();
                while(x--){
                    int front = q.front();
                    q.pop();
                    vis[front] = true;
                    for(auto neigh: graph[front]){
                        if(!vis[neigh]) q.push(neigh);
                    }
                }
            }
        }
        
        return ans;
    }
};