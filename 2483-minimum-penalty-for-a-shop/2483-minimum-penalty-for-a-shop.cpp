class Solution {
public:
    int bestClosingTime(string customers) {
        int s = customers.size();
        
        int ty=0, tn=0, y=0, n=0;
        vector<pair<int, int>> occurs;
        occurs.push_back({0,0});
        for(int i=0;i<s;i++){
            if(customers[i]=='Y'){
                y++;
                ty++;
            }
            else{
                n++;
                tn++;
            }
            occurs.push_back({y, n});
        }
        
        int penalty = INT_MAX;
        int ans = -1;
        
        for(int i=0;i<occurs.size();i++){
            int ly = occurs[i].first;
            int ln = occurs[i].second;
            int ry = ty-ly;
            
            int temp = ln+ry;
            if(temp<penalty){
                penalty = temp;
                ans = i;
            }
        }
        
        return ans;
    }
};