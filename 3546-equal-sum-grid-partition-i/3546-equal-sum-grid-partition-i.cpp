class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long> h(n);
        vector<long long> v(m);
        for (int i=0;i<n;i++){
            long long sm=0;
            for(int j=0;j<m;j++){
                sm+=grid[i][j];
            }
            h[i]=sm;
        }
        for (int i=0;i<m;i++){
            long long sm=0;
            for(int j=0;j<n;j++){
                sm+=grid[j][i];
            }
            v[i]=sm;
        }
        long long sh=accumulate(h.begin(),h.end(),0*1LL);
        
        long long sv=accumulate(v.begin(),v.end(),0*1LL);
        long long ss=0;
        for(int i=0;i<n;i++){
            ss+=h[i];
            long long lft=sh-ss;
            if(ss==lft){
                return true;
            }
        }
        ss=0;
        for(int i=0;i<m;i++){
            ss+=v[i];
            long long lft=sv-ss;
            if(ss==lft){
                return true;
            }
        }
        return false;

    }
};