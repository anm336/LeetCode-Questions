class UndergroundSystem {
public:
    unordered_map<string , vector<int>> timing;
    unordered_map<int, pair<string,int>> checkins;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkins[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string src = checkins[id].first;
        string dest = stationName;
        
        int tt = t - checkins[id].second;
        string temp = src+"/"+dest;
        
        timing[temp].push_back(tt);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double total = 0;
        int n = timing[startStation+"/"+endStation].size();
        
        for(int i=0;i<n;i++){
            total+=timing[startStation+"/"+endStation][i];
        }
        
        return (1.0*total) / n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */