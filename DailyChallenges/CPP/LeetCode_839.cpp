class Solution {
    vector<vector<int> > vec;
    unordered_map<int,unordered_set<int> > mp;
    vector<int> par;
public:
    bool comp(string &a,string &b){
        int n=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i] && (++n)>2){
                return false;
            }
        }
        return true;
    }
    int find(int i){
        if(par[i]==-1) return i;
        return par[i]=find(par[i]);
    }
    void unio(int i,int j){
        int x=find(i);
        int y=find(j);
        if(x!=y){
            par[x]=y;
        }
    }
    int numSimilarGroups(vector<string>& A) {
        int n=A.size();
        par.resize(n+1,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(comp(A[i],A[j])){
                    unio(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(par[i]==-1){
                ans++;
            }
        }
        return ans;
    }
};
