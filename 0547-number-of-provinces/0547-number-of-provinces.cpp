class Solution {
public:
    void dfs(int i,vector<int>& vis,vector<vector<int>>& adj){
        vis[i]=1;
        for(auto ele:adj[i]){
            if(!vis[ele] ){
                dfs(ele,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& g) {
        int n=g.size();
        
        vector<vector<int>> adj(n);
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( g[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};