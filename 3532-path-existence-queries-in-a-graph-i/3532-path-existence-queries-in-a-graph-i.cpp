class DisjointSet{
    public:
        vector<int> parent;
        vector<int> rank;

        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findup(int nd){
            if(parent[nd]==nd){
                return nd;
            }
            return parent[nd]=findup(parent[nd]);
        }

        void unionn(int u,int v){
            int upu=findup(u);
            int upv=findup(v);
            if(upu==upv) return;
            if(rank[upu]>rank[upv]) {
                parent[upv]=upu;
                
            }
            else if(rank[upv]>rank[upu]){
                parent[upu]=upv;
                
            } 
            else{
                parent[upv]=upu;
                rank[upu]++;
            }
        }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet D(n);
        
        for(int i=1;i<n;i++){
            
                if(abs(nums[i-1]-nums[i])<=maxDiff){
                    D.unionn(i-1,i);
                }
            
        }
        vector<bool> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            if(D.findup(queries[i][0])==D.findup(queries[i][1])){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;

    }
};