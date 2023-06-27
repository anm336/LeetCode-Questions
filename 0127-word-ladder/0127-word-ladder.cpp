class Solution {
public:
    bool isValid(string s1, string s2){
        int diff = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]) diff++;
        }
        if(diff==1) return true;
        return false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 1;
        int n = wordList.size();
        
        queue<string> q;
        vector<bool> vis(n, false);
        q.push(beginWord);
        bool found = false;
        
        while(!q.empty() && !found){
            ans++;
            int x = q.size();
            while(x--){
                string front = q.front();
                q.pop();
                
                for(int i=0;i<n;i++){
                    if(!vis[i] && isValid(front, wordList[i])){
                        //cout<<wordList[i]<<" ";
                        if(wordList[i]==endWord){
                            found = true;
                            break;
                        }
                        else{
                            q.push(wordList[i]);
                            vis[i] = true;
                        }
                    }
                }
                //cout<<endl;
            }
        }
        
        if(found) return ans;
        return 0;
    }
};