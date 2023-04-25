class SmallestInfiniteSet {
public:
    set<int> s;
    int st = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(s.empty()) return st++;
        else {
            int e = *s.begin();
            s.erase(e);
            return e;
        }
    }
    
    void addBack(int num) {
        if (num < st)
            s.insert(num);
    }
};
