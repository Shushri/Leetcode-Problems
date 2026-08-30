class DisJoint{
    private:
        vector<int> parent,rank;
    public:
        DisJoint(int n){
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find(int u){
            if(parent[u]==u) return u;
            return parent[u]=find(parent[u]);

        }
        void Union(int u,int v){
            int ultu=parent[u];
            int ultv=parent[v];
            if(ultu==ultv) return ;
            if(rank[ultu]>rank[ultv]){
                parent[ultv]=ultu;
            }
            else if(rank[ultu]<rank[ultv]){
                parent[ultu]=ultv;
            }
            else{
                
                parent[ultv]=ultu;
                rank[ultu]++;
            
            }
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisJoint Dj(n+1);
        for(int i=0;i<n;i++){
            if(Dj.find(edges[i][0])==Dj.find(edges[i][1])){
                return {edges[i][0],edges[i][1]};
            }
            else{
                Dj.Union(edges[i][0],edges[i][1]);
            }
        }
        return {};
    }
};