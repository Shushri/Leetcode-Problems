class Solution {
public:
    void dfs(int ind,vector<vector<int>>& rooms,vector<int> &vis){
        vis[ind]=1;
        for(auto &neb:rooms[ind]){
            if(!vis[neb]){
                dfs(neb,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};