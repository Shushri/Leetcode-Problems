class Disjoint{
    vector<int> rank,parent;
public:
    Disjoint(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void unionByRank(int u,int v){
        int upu=find(u);
        int upv=find(v);
        if(upu==upv) return ;
        if(rank[upu]>rank[upv]){
            parent[upv]=upu;
        }
        else if(rank[upu]<rank[upv]){
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        Disjoint D(n);
        unordered_map<string ,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                string s=acc[i][j];
                if(mpp.count(s)==0){
                    mpp[s]=i;
                }
                else{
                    D.unionByRank(i,mpp[s]);
                }
            }
        }
        vector<set<string>> vcc(n);
        for(int i=0;i<n;i++){
            
                int par=D.find(i);
                for(int j=1;j<acc[i].size();j++){
                    vcc[par].insert(acc[i][j]);
                }
         }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            
            if(vcc[i].size()>0){
                vector<string> tp;
                tp.push_back(acc[i][0]);
                for(auto ele:vcc[i]){
                    tp.push_back(ele);
                }
                ans.push_back(tp);
            }
            
        }
        return ans;

    }
};