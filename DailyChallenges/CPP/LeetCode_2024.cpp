class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0, ct = 0, cf = 0, ans = 0;
        for (int i = 0; i< answerKey.size(); ++i){
            if (answerKey[i] == 'T') ++ct; else ++cf;
            while (min(ct, cf)>k){
                if (answerKey[l++] == 'T') --ct; else --cf;
            }
            ans = max(ans, ct+cf);
        }
        return ans;
    }
};
