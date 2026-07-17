class Solution {
public:
    void dfs(int nd, vector<vector<pair<int,int>>> &adj, vector<vector<int>>& con, vector<int> &vis, int &cnt){
        vis[nd]=1;
        for(auto neb:adj[nd]){
            if(!vis[neb.first]){
                cnt+=neb.second;
                dfs(neb.first,adj,con,vis,cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<con.size();i++){
            adj[con[i][0]].push_back({con[i][1],1});
            adj[con[i][1]].push_back({con[i][0],0});
        }
        vector<int> vis(n,0);
        int cnt=0;
        dfs(0,adj,con,vis,cnt);
        return cnt;
    }
};