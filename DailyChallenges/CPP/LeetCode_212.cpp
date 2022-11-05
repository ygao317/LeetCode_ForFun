// 212. Word Search II @ 2011/11/05

class Trie{
public:
    string word;
    bool is_word=false;
    Trie* children[26]={NULL};
};

class Solution {
private:   
    Trie* root = nullptr;
    
    void insert(string &s){
        Trie* temp=root;
        for(auto &i:s){
            int k=i-'a';
            if(!temp->children[k])
                temp->children[k]=new Trie;
            temp=temp->children[k];
        }
        temp->word=s;
        temp->is_word=true;
    }
    
    void dfs(vector<vector<char>>&board, vector<string>&res, Trie* temp, int i, int j)     {

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='*' || !(temp->children[board[i][j]-'a']))
            return;
        
        temp=temp->children[board[i][j]-'a'];
        
        if(temp->is_word){
            res.push_back(temp->word);
            temp->is_word=false;
        }
        
        char temp_char = board[i][j];
        board[i][j]='*';
        
        dfs(board, res, temp, i+1, j);
        dfs(board, res, temp, i, j+1);
        dfs(board, res, temp, i-1, j);
        dfs(board, res, temp, i, j-1);
        
        board[i][j]=temp_char;
        
        return;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new Trie;
        for(auto &s:words)
            insert(s);
        vector<string>res;
        Trie* temp=root;
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                dfs(board, res, temp, i, j);
        
        delete root;
        return res;
    }
};
