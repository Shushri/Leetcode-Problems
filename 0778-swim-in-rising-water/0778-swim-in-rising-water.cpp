class Solution {
public:
   int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> dr={0,-1,0,1};
        vector<int> dc={-1,0,1,0};
        vector<vector<int>> vis(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        int ans=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j]=1;
            ans=max(ans,wt);
            if(i==n-1 && j==n-1) return ans;
            for(int pos=0;pos<4;pos++){
                int rw=i+dr[pos];
                int cl=j+dc[pos];
                if(rw>=0 && rw<n && cl>=0 && cl<n && !vis[rw][cl]){
                    pq.push({grid[rw][cl],{rw,cl}});
                }
            }
        }
        return ans;
    }
};