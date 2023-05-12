class FrequencyTracker {
public:
    unordered_map<int, int> cnt;
    map<int, unordered_set<int>> fre;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        ++cnt[number];
        if (cnt[number]>1){
            fre[cnt[number]-1].erase(number);
            if (fre[cnt[number]-1].empty()) fre.erase(cnt[number]-1);
        }
        fre[cnt[number]].insert(number);
    }
    
    void deleteOne(int number) {
        if (cnt[number] == 0) return;
        --cnt[number];
        fre[cnt[number]+1].erase(number);
        if (fre[cnt[number]+1].empty()) fre.erase(cnt[number]+1);
        if (cnt[number] >0) fre[cnt[number]].insert(number);
    }
    
    bool hasFrequency(int frequency) {
        //if (fre.empty()) return false;
        return !fre[frequency].empty();
    }
};
