class Allocator {
private:
    map<int, int> line;  // record the block info by +1/-1
    unordered_map<int, vector<pair<int, int>>> record; // mid -> (start, size)
public:
    Allocator(int n) {
        line.clear();
        record.clear();
        line[n] = 1;
    }
    
    int allocate(int size, int mID) {
        int idx = 0;
        for (auto [k, v]: line){
            if (v == 1){ 
                if (k-idx >= size){ // can allocate
                    if (line[idx] == -1) line.erase(idx);
                    else line[idx] = 1;
                    
                    if (line[idx + size] == 1) line.erase(idx+size);
                    else line[idx + size] = -1;
                    
                    record[mID].push_back({idx, size});
                        
                    return idx;
                }
            }else{ // v == -1
                idx = k; // new starting points
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int sz = 0;
        for (auto [idx, size]: record[mID]){
            if (line[idx] == 1) 
                line.erase(idx);
            else line[idx] = -1;
            
            if (line[idx+size] == -1)
                line.erase(idx+size);
            else
                line[idx+size] = 1;
            
            sz += size;
        }
        record.erase(mID);
        return sz;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
