class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> diss(n,INT_MAX);
        diss[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==n-1){
                return diss[n-1];
            }
            for(auto ele:adj[node]){
                int wtt=ele.second;
                int vv=ele.first;
                if(dist+wtt < diss[vv]){
                    diss[vv]=dist+wtt;
                    pq.push({dist+wtt,vv});
                }
            }
        }
        return -1;
    }
};