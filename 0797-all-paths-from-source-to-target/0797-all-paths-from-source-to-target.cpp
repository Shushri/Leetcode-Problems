class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>path;
        vector<int>p;
         dfs(path,p,graph,0,n);
        
        return path;
    }
    void dfs(vector<vector<int>>&path,vector<int>&p,vector<vector<int>> &graph,int i,int n){
      p.push_back(i);
      if(i==n-1){
        path.push_back(p);
        p.pop_back();
        return;
      }
     for(int j: graph[i]) dfs(path,p,graph,j,n);
     p.pop_back();
      }
};