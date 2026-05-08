class Solution {
public:
    bool dfs(int nd,int cl,vector<vector<int>>& graph, vector<int> &clr){
        clr[nd]=cl;
        for(auto ele:graph[nd]){
            if(clr[ele]==-1 && dfs(ele,!cl,graph,clr)==false){
                return false;
            }
            else if(clr[ele]==cl){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> clr(n,-1);//for alternate colours 0 and 1
        for(int i=0;i<n;i++){
            if(clr[i]==-1 && dfs(i,0,graph,clr)==false){
                return false;
            }
        }
        return true;

    }
};