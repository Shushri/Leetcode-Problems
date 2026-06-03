class Solution {
public:
    void dfs(int nd, vector<int>& vs,vector<vector<int>>& adj){
        vs[nd]=1;
        for(auto ele:adj[nd]){
            if(vs[ele]==0){
                dfs(ele,vs,adj);
            }
        }

    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size()<n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<conn.size();i++){
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }
        vector<int> vs(n,0);
        int cc=0;
        for(int i=0;i<n;i++){
            if(vs[i]==0){
                cc++;
                dfs(i,vs,adj);
            }

        }
        return cc-1;

        
    }
};