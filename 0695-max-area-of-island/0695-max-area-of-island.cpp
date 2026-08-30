class DisJoint{
    
        
    public:
        vector<int> parent,size;
        DisJoint(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int find(int u){
            if(parent[u]==u) return u;
            return parent[u]=find(parent[u]);

        }
        void UnionbySize(int u,int v){
            int ultu=find(u);
            int ultv=find(v);
            if(ultu==ultv) return ;
            if(size[ultu]>size[ultv]){
                parent[ultv]=ultu;
                size[ultu]+=size[ultv];
            }
            else if(size[ultu]<size[ultv]){
                parent[ultu]=ultv;
                size[ultv]+=size[ultu];
            }
            else{
                
                parent[ultv]=ultu;
                size[ultu]+=size[ultv];
            
            }
        }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> dr={0,1};
        vector<int> dc={1,0};

        DisJoint D(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 ) continue;
                int u=i*m+j;
               
                for(int p=0;p<2;p++){
                    int rw=i+dr[p];
                    int cl=j+dc[p];
                    if(rw>=0 && rw<n && cl>=0 && cl<m && grid[rw][cl]==1){
                        int v=rw*m+cl;
                        D.UnionbySize(u,v);
                    }
                }
            }
        }

        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int x=i*m+j;
                    mx=max(mx,D.size[x]);
                }
            }
        }
        return mx;

    }
};

