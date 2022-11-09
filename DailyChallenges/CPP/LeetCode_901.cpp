//901. Online Stock Span @ 2022/11/09
class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while(!stack.empty() && stack.back().first <= price){
            span += stack.back().second;
            stack.pop_back();
        }
        stack.push_back({price, span});
        return span;
    }
private:
    vector<pair<int, int>> stack;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
