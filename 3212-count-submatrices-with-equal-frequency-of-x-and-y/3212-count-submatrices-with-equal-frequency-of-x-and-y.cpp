class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<int,int>>> mat(n,vector<pair<int,int>>(m));
        for(int i=0;i<n;i++){
            int x=0;
            int y=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    x++;
                }
                else if(grid[i][j]=='Y'){
                    y++;
                }
                mat[i][j]={x,y};
            }
        }

        for(int i=1;i<n;i++){
            for(int j=m-1;j>=0;j--){
                int f=mat[i-1][j].first;
                int s=mat[i-1][j].second;
                mat[i][j].first+=f;
                mat[i][j].second+=s;
                
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(mat[i][j].first!=0 && mat[i][j].first==mat[i][j].second){
                    ans++;
                }
            }
            
        }
        return ans;

    }
};