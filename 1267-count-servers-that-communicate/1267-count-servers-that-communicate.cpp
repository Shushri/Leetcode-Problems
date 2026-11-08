class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> rsm(n);
        vector<int> csm(m);
        int s;
        for(int i=0;i<n;i++){
            s=0;
            for(int j=0;j<m;j++){
                s+=grid[i][j];
            }
            rsm[i]=s;
        }
        
        for(int i=0;i<m;i++){
            s=0;
            for(int j=0;j<n;j++){
                s+=grid[j][i];
            }
            csm[i]=s;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(rsm[i]>1 || csm[j]>1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};