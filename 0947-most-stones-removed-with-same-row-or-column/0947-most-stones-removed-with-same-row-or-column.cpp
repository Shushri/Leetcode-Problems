class Disjoint {
    vector<int> rank,parent;
public:
    
    Disjoint(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find_ult_p(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find_ult_p(parent[u]);
    }
    void unionByRank(int u,int v){
        int ultu=find_ult_p(u);
        int ultv=find_ult_p(v);
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int mx_rw=0;
        int mx_cl=0;
        for(auto ele:stones){
            mx_rw=max(mx_rw,ele[0]);
            mx_cl=max(mx_cl,ele[1]);
        }        
        int nodes_cnt=mx_rw+mx_cl+2;
        Disjoint D(nodes_cnt);
        unordered_map<int,int> mpp;
        for(auto ele:stones){
            int rw=ele[0];
            int cl=ele[1]+mx_rw+1;
            D.unionByRank(rw,cl);
            mpp[rw]=1;
            mpp[cl]=1;
        }
        int ans=0;
        for(auto ele:mpp){
            if(ele.first==D.find_ult_p(ele.first)){
                ans++;
            }
        }
        return n-ans;
    }
};