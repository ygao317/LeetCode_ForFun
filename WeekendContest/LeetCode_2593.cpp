class Solution {
public:
    long long findScore(vector<int>& nums) {
        auto cmp = [](const vector<int>& left, const vector<int>& right) { return (left[0] > right[0]) || ((left[0] == right[0]) && (left[1] > right[1])); };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 0; i < nums.size(); ++i)
            pq.push({nums[i], i});
        
        vector<int> visited(nums.size(), 0);
        long long ans = 0;
        while(!pq.empty()){
            auto a = pq.top(); pq.pop();
            if (visited[a[1]]) continue;
            //cout << a[0] << " " << a[1]  << endl;
            ans += a[0];
            visited[a[1]] = 1;
            if (a[1] > 0) visited[a[1]-1] = 1;
            if (a[1] < nums.size()-1) visited[a[1]+1] = 1;
        }
        return ans;
    }
};
