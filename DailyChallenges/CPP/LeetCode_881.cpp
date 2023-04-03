class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size(), ans = 0;
        while (l < r){
            if (people[--r] + people[l] <= limit) l++;
            ans++;
        }
        return ans;
    }
};
