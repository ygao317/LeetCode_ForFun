class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        sort(tickets.begin(), tickets.end());
        map<string, vector<int>> m;
        for (int i=0; i<n; ++i) m[tickets[i][0]].push_back(i);
        vector<int> trips;
        vector<bool> used(n, false);
        
        function<bool(string&)> dfs = [&](string& from){
            if (trips.size() == n) return true;
            for (int i: m[from]){
                if (used[i]) continue;
                used[i] = true;
                trips.push_back(i);
                bool done = dfs(tickets[i][1]);
                if (done) return done;
                used[i] = false;
                trips.pop_back();
            }
            return false;
        };
        vector<string> ans; ans.reserve(n+1);
        ans.emplace_back("JFK");
        dfs(ans[0]);
        for (int i: trips) ans.emplace_back(tickets[i][1]);
        return ans;
    }
};
