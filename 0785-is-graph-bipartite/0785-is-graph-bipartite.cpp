class Solution {
public:
    bool dfs(int nd,int cl, vector<vector<int>>& g,vector<int> &col ){
        col[nd]=cl;
        for(auto ele:g[nd]){
            if(col[ele]==-1 && dfs(ele,!cl,g,col)==false){//ek baar false aa gya to baar baar false hi aaana hai chaaahe bhale hi col[ele]==-1 hai
                return false;
            }
            else if(col[ele]==cl){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            
            if(col[i]==-1){
                if(dfs(i,0,g,col)==false){
                    return false;
                }
            }
            
        }
        return true;

    }
};