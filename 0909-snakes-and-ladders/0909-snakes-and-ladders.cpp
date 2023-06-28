class Solution {
public:
    int helper(vector<int> &myboard, int s){
        int target = s;
        int rolls = 0;
        
        queue<int> q;
        q.push(1);
        vector<bool> vis(s+1, false);
        vis[1] = true;
        bool reached = false;
        while(!q.empty() && !reached){
            rolls++;
            int x = q.size();
            while(x-- && !reached){
                int front = q.front();
                q.pop();
                for(int i=1;i<=6;i++){
                    if(front+i<=target && !vis[front+i]){
                        if(front+i == target || myboard[front+i] == target){
                            reached = true;
                            break;
                        }
                        if(myboard[front+i] == -1){
                            vis[front+i] = true;
                            q.push(front+i);
                        }
                        else{
                            vis[front+i] = true;
                            int go = myboard[front+i];
                            //vis[go] = true;
                            q.push(go);
                        }
                    }
                }
            }
        }
        
        if(reached) return rolls;
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int s = n*n;
        vector<int> myboard(s+1);
        int k = 1;
        int start = 0;
        
        for(int i=n-1;i>=0;i--){
            if(start == 0){
                for(int j=0;j<n;j++){
                    myboard[k++] = board[i][j];
                }
                start = 1;
            }
            else{
                for(int j=n-1;j>=0;j--){
                    myboard[k++] = board[i][j];
                }
                start = 0;
            }
        }
        
        //for(auto x: myboard) cout<<x<<" ";
        return helper(myboard, s);
        //return 0;
    }
};