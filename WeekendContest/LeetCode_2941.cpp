class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size(), p = skill[0] + skill[n-1]; 
        long long ans = skill[0] * skill[n-1];
        for (int i=1; i< n/2; ++i){
            if ((skill[i] + skill[n-1-i]) != p)
                return -1;
            ans += skill[i] * skill[n-1-i];
        }
        return ans;
    }
};
