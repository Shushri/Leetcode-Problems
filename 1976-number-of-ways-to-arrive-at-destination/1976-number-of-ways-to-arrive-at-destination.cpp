class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mdd=1e9 + 7;
        vector<vector<pair<int,int>>> arr(n);
        for(int i=0;i<roads.size();i++){
            
            arr[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            arr[roads[i][1]].push_back({roads[i][0],roads[i][2]});

        }
        vector<long long> vis(n,LLONG_MAX);
        vector<long long> way(n,0);
        vis[0]=0;
        way[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            long long wt=pq.top().first;
            int nd=pq.top().second;
            pq.pop();
            for(auto p:arr[nd]){
                int nd2=p.first;
                long long wt2=p.second;

                
                if((wt+wt2)<vis[nd2]){
                        
                        vis[nd2]=wt+wt2;
                        way[nd2]=way[nd];
                        pq.push({wt+wt2,nd2});
                }
                else if((wt+wt2)==vis[nd2]){
                        way[nd2]=(way[nd2]+way[nd])%mdd;

                }
            
            }
        }
        return way[n-1];
    }
};