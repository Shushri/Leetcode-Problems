class DisJoint {
private:
    vector<int> parent, size;
public:
    

    DisJoint(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return u;

        return parent[u] = find(parent[u]);
    }

    void UnionbySize(int u, int v) {
        int ultu = find(u);
        int ultv = find(v);

        if (ultu == ultv)
            return;

        if (size[ultu] < size[ultv])
            swap(ultu, ultv);

        parent[ultv] = ultu;
        size[ultu] += size[ultv];
    }
};

class Solution {
public:
    vector<bool> friendRequests(int num, vector<vector<int>>& res, vector<vector<int>>& req) {
        int m=res.size();
        int n=req.size();
        DisJoint D(num+1);
        vector<bool> ans(n);
        for(int i=0;i<n;i++){
            int f=0;
            for(int j=0;j<m;j++){
                if(((D.find(req[i][0])==D.find(res[j][0]))&&(D.find(req[i][1])==D.find(res[j][1]))) || ((D.find(req[i][0])==D.find(res[j][1]))&&(D.find(req[i][1])==D.find(res[j][0])))){
                    f=1;
                }
                
            }
            if(f==0){
                ans[i]=true;
                D.UnionbySize(req[i][0],req[i][1]);
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};