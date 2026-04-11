class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                vis[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int a=q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(j!=a && vis[j]!=1 && mat[a][j]==1){
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};