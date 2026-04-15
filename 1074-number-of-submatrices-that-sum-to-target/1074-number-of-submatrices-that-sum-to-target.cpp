class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<m;i++){
            
            for(int j=1;j<n;j++){
                mat[j][i]+=mat[j-1][i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                unordered_map<int,int> mpp;
                mpp[0]=1;
                int presm=0;
                for(int k=0;k<m;k++){
                    int sm1 = mat[j][k] - (i > 0 ? mat[i-1][k] : 0);
                    presm+=sm1;
                    int need=presm-t;
                    if(mpp.find(need)!=mpp.end()){
                        ans+=mpp[need];
                    }
                    mpp[presm]++;
                }
            }
        }
        return ans;
    }
};