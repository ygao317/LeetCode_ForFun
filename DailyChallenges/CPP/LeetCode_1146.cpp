class SnapshotArray {
private:
    int _id = 0;
    vector<vector<pair<int, int>>> _a; // {id, val}
public:
    SnapshotArray(int length) {
        _a = vector<vector<pair<int, int>>>(length, {{_id, 0}});
    }
    
    void set(int index, int val) {
        if (_a[index].back().first == _id) 
            _a[index].back().second = val; 
        else 
            _a[index].push_back({_id, val});
    }
    
    int snap() {
        return _id++; 
    }
    
    int get(int index, int snap_id) {
        auto itr = upper_bound(_a[index].begin(), _a[index].end(), snap_id, [](auto id, auto& p){ return p.first > id;});
        return prev(itr)->second;
    }
};
