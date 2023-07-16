class Solution {
public:
    struct Node{ Node* child[26]; bool isEnd = false;};
    int longestValidSubstring(string word, vector<string>& forbidden) {
        Node *root = new Node();
        for (auto& s: forbidden){
            Node * node = root;
            for (int i=s.size()-1; i>=0; --i){ // reverse
                int _i = s[i] - 'a';
                if (!node->child[_i]) node->child[_i] = new Node();
                node = node->child[_i];
            }
            node->isEnd = true;
        }
        
        int l = 0, ans = 0; 
        for (int i = 0; i < word.size(); ++i){
            Node * node = root;
            for (int j=i; j>=l; --j){
                int _i = word[j] - 'a';
                if (!node->child[_i]) break;
                if (node->child[_i]->isEnd){
                    l = j+1; break;
                }
                node = node->child[_i];
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
