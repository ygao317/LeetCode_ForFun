class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.size(), nb = b.size();
        if (na > nb) return addBinary(b, a);
        a = string(nb-na, '0') + a;
        int carrier = 0;
        for (int i = nb-1; i >=0 ; --i){
            carrier = (a[i]-'0') + (b[i]-'0') + carrier;
            b[i] = '0' + (carrier % 2);
            carrier = carrier / 2;
        }
        return ((carrier == 1)? "1":"") + b;
    }
};
