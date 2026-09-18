class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& iswater) {
        int n=iswater.size();
        int m=iswater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(iswater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                      
                }
            }
        }
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int h=q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int rw=r+dr[d];
                int cl=c+dc[d];
                if(rw>=0 && rw<n && cl>=0 && cl<m && vis[rw][cl]==0){
                    q.push({{rw,cl},h+1});
                    ans[rw][cl]=h+1;
                    vis[rw][cl]=1;
                }
            }
        }
        return ans;
    }
};