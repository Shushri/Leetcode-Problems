class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
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
            int f=0;
            for(int i=0;i<sz;i++){
                pair<int,int> tp=q.front();
                q.pop();
                int r=tp.first;
                int c=tp.second;
                if(r-1>=0 && grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                    f=1;
                }
                if(r+1<n && grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    q.push({r+1,c});f=1;
                }
                if(c-1>=0 && grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    q.push({r,c-1});f=1;
                }
                if(c+1<m && grid[r][c+1]==1){
                    grid[r][c+1]=2;
                    q.push({r,c+1});f=1;
                }

            }
            if(f==1) ans++;
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