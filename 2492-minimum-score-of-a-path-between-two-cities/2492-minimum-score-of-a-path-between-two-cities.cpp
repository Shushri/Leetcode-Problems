class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<r.size();i++){
            int u=r[i][0];
            int v=r[i][1];
            int e=r[i][2];
            adj[u].push_back({v,e});
            adj[v].push_back({u,e});
        }
        int ans=INT_MAX;
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1);
        vis[1]=1;
        while(!q.empty()){
            int nd=q.front();
            q.pop();
            for(auto [nr,eg]:adj[nd]){
                ans=min(ans,eg);
                if(!vis[nr]){
                    q.push(nr);
                    vis[nr]=1;
                    
                }
            }        
        }
        if(!vis[n]){
            return INT_MAX;
        }
        return ans;

    }
};