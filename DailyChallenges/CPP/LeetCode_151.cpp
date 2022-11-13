// 151. Reverse Words in a String @ 2022/11/13

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end()); // reverse whole string first
        int i=0, j=0, n=s.size();
        while(j<n){
            // Remove leading spaces
            while(j<n && s[j]==' ') j++;
            if (j == n) break; // no word to copy
            
            int k = j; // word begin
            while(j<n && s[j]!=' ') j++; //word end
            
            if (i>0) s[i++] = ' '; // seperator
            copy(s.begin()+k, s.begin()+j, s.begin()+i); 
            reverse(s.begin()+i, s.begin()+i+(j-k));
            
            i += j-k; // update i
        }
        s.resize(i); // remove extra at the end
        return s;
    }
};
