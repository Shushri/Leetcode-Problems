class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    dis[i][j]=0;
                }
            }
        }
        vector<int> dir={0,1,0,-1};
        vector<int> dic={1,0,-1,0};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int d=q.front().first;
                int r=q.front().second.first;
                int c=q.front().second.second;
                q.pop();

                for(int j=0;j<4;j++){
                    int rw=r+dir[j];
                    int cl=c+dic[j];

                    if(rw>=0 && rw<n && cl>=0 && cl<m && mat[rw][cl]==1 && !vis[rw][cl]){
                        q.push({d+1,{rw,cl}});
                        dis[rw][cl]=d+1;
                        vis[rw][cl]=1;
                    }
                }


            }
                

        }
        return dis;

    }
};