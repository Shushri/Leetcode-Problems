class Solution {
    
public:
    int findup(int nd,vector<int> &parent){   //ultimate parent
        if(nd==parent[nd]){
            return nd;
        }
        //compression
        return parent[nd]=findup(parent[nd],parent);
    }
    void unionByRank(int u,int v,vector<int> &parent,vector<int> &rank){
        int up_u=findup(u,parent);
        int up_v=findup(v,parent);
        if(up_u==up_v){
            return;
        }
        if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }
        else if(rank[up_u]>rank[up_v]){
            parent[up_v]=up_u;
        }
        else{
            parent[up_u]=up_v;
            rank[up_v]++;
        }

    }
    int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size()<n-1){
            return -1;
        }
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<con.size();i++){
            int u=con[i][0];
            int v=con[i][1];
            unionByRank(u,v,parent,rank);
        }

        int c=0;
        for(int i=0;i<n;i++){
            if(i==parent[i]){
                c++;
            }
        }
        
        return c-1;






    }
};