// 295. Find Median from Data Stream @ 2022/11/12

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ms.insert(num);
        even = !even;
        if (itr == ms.end() || (even && *itr <= num)) ++itr; // C++ 11 ensure that same value add to the end
        if (!even && *itr > num) --itr;
    }
    
    double findMedian() {
        return (!even) ? *itr : (*itr + *prev(itr)) / 2.0;
    }
    
private:
    multiset<int> ms;
    multiset<int>::iterator itr = ms.begin();
    bool even = true;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
