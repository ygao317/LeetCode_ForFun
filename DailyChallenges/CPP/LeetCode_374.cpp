// 374. Guess Number Higher or Lower @ 2022/11/16

class Solution {
public:
    int guessNumber(int n) {
        int l{0}, r{n}, m{n/2}, rtn;

        while (rtn = guess(m=(l+(r-l)/2)))          
            if (rtn<0) r = m-1; else l = m+1;
        
        return m;
    }
};
