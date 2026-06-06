class Solution {
public:
    int timer=1;
    void dfs(int nd,int pr,vector<vector<int>> &ans, vector<int> &vis,vector<vector<int>> &adj,vector<int> &tin,vector<int> &low){
        vis[nd]=1;
        tin[nd]=timer;
        low[nd]=timer;
        timer++;

        for(auto p:adj[nd]){
            if(p==pr) continue;
            if(!vis[p] ){
                dfs(p,nd,ans,vis,adj,tin,low);
                low[nd]=min(low[nd],low[p]);
                if(low[p]>tin[nd]){
                    
                    ans.push_back({nd,p});
                }
            }
            else{
                low[nd]=min(low[nd],low[p]);
            }
        }
         
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        for(int i=0;i<con.size();i++){
            adj[con[i][1]].push_back(con[i][0]);
            adj[con[i][0]].push_back(con[i][1]);
        }
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> vis(n);
        vector<vector<int>> ans;
       
        dfs(0,-1,ans,vis,adj,tin,low);
        return ans;
    }
};