class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            int fl=0;
            for(int i=0;i<sz;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                
                for(int j=0;j<4;j++){
                    int rw=r+dr[j];
                    int cl=c+dc[j];
                    if(rw>=0 && rw<n && cl>=0 && cl<m && grid[rw][cl]==1){
                        grid[rw][cl]=2;
                        q.push({rw,cl});
                        fl=1;
                    }
                }
            }
            if (fl==1) ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;



    }
};