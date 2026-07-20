class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k=k%(n*m);
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=i*m+j;
                idx=(idx+k)%(n*m);
                ans[(idx)/m][(idx)%m]=grid[i][j];
            }
        }
        return ans;
    }
};