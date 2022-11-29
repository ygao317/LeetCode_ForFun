// 380. Insert Delete GetRandom O(1) @ 2022/11/29

class RandomizedSet {
private:
    vector<int> a;
    unordered_map<int, int> m;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        else{
            a.push_back(val);
            m[val] = a.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        else{
            m[a.back()] = m[val];
            a[m[val]] = a.back();
            m.erase(val);
            a.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};
