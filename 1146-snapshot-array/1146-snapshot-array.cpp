class SnapshotArray {
public:
    vector<vector<pair<int,int>>> records;
    int snaps;
    
    SnapshotArray(int length) {
        snaps = 0;
        records.resize(length);
        for(int i=0;i<length;i++){
            records[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        records[index].push_back({snaps, val});
    }
    
    int snap() {
       return snaps++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(records[index].begin(), records[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it) -> second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */