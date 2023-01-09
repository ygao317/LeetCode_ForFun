class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int num: nums) q.push(num);
        long long ans = 0;
        int cnt = 0;
        for (; q.top() != 1 && cnt < k; ++cnt){
            int num = q.top(); q.pop();
            q.push((num+2)/3);
            ans += num;
        }
        return (cnt == k) ? ans : (ans + (k-cnt)); 
    }
};
