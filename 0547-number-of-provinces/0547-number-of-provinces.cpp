class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& ic){
        vis[i][j]=1;
        int n=ic.size();
        
        for(int p=0;p<n;p++){
                if( ic[j][p]==1 && vis[j][p]==0){
                    dfs(j,p,vis,ic);
                }
        }
    }
    int findCircleNum(vector<vector<int>>& ic) {
        int n=ic.size();
        int ans=0;
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && ic[i][j]==1){
                    ans++;
                    dfs(i,j,vis,ic);
                }
            }
        }
        return ans;
    }
};