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
        vector<int> dir={0,1,0,-1};
        vector<int> dic={1,0,-1,0};
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            int f=0;
            for(int i=0;i<sz;i++){
                pair<int,int> tp=q.front();
                q.pop();
                int r=tp.first;
                int c=tp.second;
                for(int j=0;j<4;j++){
                    int rw=r+dir[j];
                    int cl=c+dic[j];
                    if(rw>=0 && rw<n && cl>=0 && cl<m &&  grid[rw][cl]==1){
                        grid[rw][cl]=2;
                        q.push({rw,cl});
                        f=1;
                    }
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