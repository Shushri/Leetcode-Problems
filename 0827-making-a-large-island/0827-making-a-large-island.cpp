class Disjoint{
    
public:
vector<int> size,parent;
    Disjoint(int n){
        size.resize(n,1);
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
    void unionBySize(int u,int v){
        int upu=find(u);
        int upv=find(v);
        if(upu==upv) return ;
        if(size[upu]>size[upv]){
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
        else if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else{
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint D(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                 vector<int> dr={0,1,0,-1};
                 vector<int> dc={1,0,-1,0};
                 for(int p=0;p<4;p++){
                    int rw=i+dr[p];
                    int cl=j+dc[p];
                    if(rw>=0 && rw<n && cl>=0 && cl<n && grid[rw][cl]==1){
                        int cell=i*n+j;
                        int new_cell=rw*n+cl;
                        D.unionBySize(cell,new_cell);
                    }
                 }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                 vector<int> dr={0,1,0,-1};
                 vector<int> dc={1,0,-1,0};
                 unordered_set<int> st;
                 for(int p=0;p<4;p++){
                    int rw=i+dr[p];
                    int cl=j+dc[p];
                    if(rw>=0 && rw<n && cl>=0 && cl<n && grid[rw][cl]==1){
                        int cell=i*n+j;
                        int new_cell=rw*n+cl;
                        st.insert(D.find(new_cell));
                    }
                 }
                int sm=0;
                 for(auto ele:st){
                    sm+=D.size[ele];
                 }
                 sm+=1;
                 mx=max(mx,sm);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int p=D.parent[i*n+j];
                    mx=max(mx,D.size[p]);
                }
            }
        }
        return mx;


    }
};