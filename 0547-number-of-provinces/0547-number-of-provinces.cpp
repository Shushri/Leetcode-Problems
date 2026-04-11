class Solution {
public:
    void dfs(int node, vector<vector<int>>& mat, vector<int>& vis) {
        vis[node] = 1;
        for(int j = 0; j < mat.size(); j++) {
            if(!vis[j] && mat[node][j] == 1) {
                dfs(j, mat, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> vis(n, 0);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i, mat, vis);
            }
        }
        return ans;
    }
};