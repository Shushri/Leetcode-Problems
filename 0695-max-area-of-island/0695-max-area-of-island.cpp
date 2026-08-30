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
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 || grid[i][j]==2) continue;
                int u=i*m+j;
                grid[i][j]=2;
                st.insert(D.find(u));
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
        for(auto ele:st){
            mx=max(mx,D.size[ele]);
        }
        return mx;

    }
};

/*
[2,1,0,1,0],
[1,0,1,1,0],
[1,1,1,1,1],
[1,0,1,1,1],
[0,0,1,0,1],
[0,0,0,1,0],
[1,1,1,0,1],
[0,1,1,1,0],
[0,1,0,1,0]]*/