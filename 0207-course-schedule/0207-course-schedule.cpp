class Solution {
public:
    bool dfs(int nd,vector<vector<int>> &sub,vector<int> &vis,vector<int> &dfsvis){
        vis[nd]=1;
        dfsvis[nd]=1;
        for(auto p:sub[nd]){
            if(!vis[p]){
                if(dfs(p,sub,vis,dfsvis)) return true;
            }
            else{
                if(dfsvis[p]){
                    return true;
                }
            }
        }
        dfsvis[nd]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> sub(n);
        for(int i=0;i<pre.size();i++){
            if(pre[i][1]==pre[i][0]){
                return false;
            }
            sub[pre[i][1]].push_back(pre[i][0]);
        }
        //using dfs
        // for(auto ele : sub){
        //     for(auto x:ele){
        //         cout<<x<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        bool ans=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,sub,vis,dfsvis)) return false;
            }
        }
        return true;


        
    }
};