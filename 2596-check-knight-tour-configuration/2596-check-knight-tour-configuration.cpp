class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<int> xdir = {-1,1,2,2,1,-1,-2,-2};
        vector<int> ydir = {-2,-2,-1,1,2,2,-1,1};
        int n = grid.size();
        
        if(grid[0][0]!=0) return false;
        int i=0,j=0;
        
        int num=0;
        while(num<(n*n-1)){
            int target = num+1;
            bool found = false;
            for(int k=0;k<8;k++){
                int newi = i+xdir[k];
                int newj = j+ydir[k];
                if(newi>=0 && newi<n && newj>=0 && newj<n){
                    if(grid[newi][newj] == target){
                        //cout<<grid[newi][newj]<<" "<<target<<" "<<newi<<" "<<newj<<endl;
                        found = true;
                        i=newi;
                        j=newj;
                        break;
                    }
                }
            }
            if(!found) return false;
            num++;
        }
        
        return true;
    }
};