class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        if(grid[0][0]==1){
            return -1;
        }
        vector<int> dc={1,1,-1,-1,0,1,0,-1};
        vector<int> dr={-1,1,1,-1,1,0,-1,0};
        dis[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int d=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for(int p=0;p<8;p++){
                int rw=i+dr[p];
                int cl=j+dc[p];
                if(rw<n && rw>=0 && cl<n && cl>=0 && grid[rw][cl]==0 && d+1<dis[rw][cl] ){
                    q.push({d+1,{rw,cl}});
                    dis[rw][cl]=d+1;
                }
            }
        }
        if(dis[n-1][n-1]==INT_MAX){
            return -1;
        }
        return dis[n-1][n-1];
        
    }
};