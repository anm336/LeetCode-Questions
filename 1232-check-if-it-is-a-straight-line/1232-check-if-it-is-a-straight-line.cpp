class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool ans = true;
        int n = coordinates.size();
        double slope;
        if(coordinates[1][1] - coordinates[0][1] == 0) slope = 0;
        else if(coordinates[1][0] - coordinates[0][0] == 0) slope = INT_MAX;
        else slope = (1.0*(coordinates[1][1]- coordinates[0][1])) / (1.0*(coordinates[1][0]- coordinates[0][0]));
        
        for(int i=2;i<n;i++){
            double tempslope;
            if(coordinates[i][1] - coordinates[i-1][1] == 0) tempslope = 0;
            else if(coordinates[i][0] - coordinates[i-1][0] == 0) tempslope = INT_MAX;
            else tempslope = (1.0*(coordinates[i][1]- coordinates[i-1][1])) / (1.0*(coordinates[i][0]- coordinates[i-1][0]));
            //cout<<tempslope<<endl;
            if(tempslope != slope){
                ans=false;
                break;
            }
        }
        return ans;
    }
};