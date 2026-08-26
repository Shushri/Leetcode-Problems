class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<int> dc={1,1,-1,-1,0,1,0,-1};
        vector<int> dr={-1,1,1,-1,1,0,-1,0};
        int d=1;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front().first;
                int j=q.front().second;
                if(i==n-1 && j==n-1) return d;
                q.pop();
                for(int p=0;p<8;p++){
                    int rw=i+dr[p];
                    int cl=j+dc[p];
                    if(rw<n && rw>=0 && cl<n && cl>=0 && grid[rw][cl]==0 ){
                        q.push({rw,cl});
                        grid[rw][cl]=1;
                        
                    }
                }
            }
            d++;
        }
        
            return -1;
        
        
        
    }
};