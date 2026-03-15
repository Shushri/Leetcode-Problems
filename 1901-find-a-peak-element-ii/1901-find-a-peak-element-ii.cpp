class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left=j-1>=0?mat[i][j-1]:-1;
                int right=j+1<m?mat[i][j+1]:-1;
                int top=i-1>=0?mat[i-1][j]:-1;
                int down=i+1<n?mat[i+1][j]:-1;
                if(mat[i][j]>left && mat[i][j]>right && mat[i][j]>top && mat[i][j]>down){
                    return {i,j};
                }
            }
        }
        return {-1,-1};

    }
};