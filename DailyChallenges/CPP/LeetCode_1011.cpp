class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       function<bool(int)> check = [&](int w){
           int d = 0, i = 0;
           while (i < weights.size()){
               int wd = 0;
               while (wd < w && i <weights.size()){
                   if (wd + weights[i] > w) break;
                   else wd += weights[i++];
               }
               if (++d>days) return false;
           }
           return true;
        };

       int l = 0; int r = 0;
       for(int w:weights){
           l = max(l, w);r += w;
       }

       while (l<r){
            int m = (l + r) / 2;
            if (check(m)) r=m; else l=m+1;
       }

       return l;
    }
};
