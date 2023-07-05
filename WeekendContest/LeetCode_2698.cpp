class Solution {
public:
    int punishmentNumber(int n) {
        function<bool(int, int, int)> check = [&](int i, int s, int l){
            //cout << i << " " << s << " " << l << endl;
            if (s+l == i) return true;
            if (s>i) return false;
            for (int j = 1; ; ++j){
                int b = int(pow(10,j));
                int k = l / b;
                if (k==0) break;
                if (check(i, s+k, l%b)) return true;
            }
            return false;
        };
        int ans = 0;
        for (int i=1; i<=n; ++i){
            int sq = i * i;
            if (check(i,0, sq)) ans += sq;
        }
        return ans;
    }
};
