class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]<b[0]) return true;
        else if(a[0]==b[0]){
            if(a[1]<b[1]) return true;
            else if(a[1]==b[1]){
                if(a[2]<b[2]) return true;
                return false;
            }
        }
        return false;
    }
    
    int maxHeight(vector<vector<int>>& cuboid) {
        for(auto &a: cuboid) {
            sort(a.begin(), a.end());
        }
        sort(cuboid.begin(), cuboid.end(), comp);
        
        vector <int> len(cuboid.size(),0);
        int h = 0, ans = 0;
        for(int i = 0; i<cuboid.size(); i++){
            len[i] = cuboid[i][2];
            for(int j = 0; j<i; j++){
			//Same old LIS 
                if(cuboid[i][0]>=cuboid[j][0] and cuboid[i][1]>=cuboid[j][1] and cuboid[i][2]>=cuboid[j][2]){
                    if(len[i]<len[j]+cuboid[i][2]) len[i] = len[j]+cuboid[i][2];
                }
            }
        }
        
        int fans = 0;
        for(int i=0;i<len.size();i++) fans = max(fans, len[i]);
        return fans;
    }
};