class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int g: gifts)
            pq.push(g);
        
        while (k-- > 0){
            int g = pq.top(); pq.pop();
            pq.push(sqrt(g));
        }
        
        long long ans = 0L;
        while (!pq.empty()){
            ans += pq.top(); pq.pop();
        }
        
        return ans;
    }
};
