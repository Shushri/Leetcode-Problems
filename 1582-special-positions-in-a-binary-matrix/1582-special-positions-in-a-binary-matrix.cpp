class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                int o1=0;
                int o2=0;
                if(mat[i][j]==1){
                    
                    for(int k=0;k<n;k++){
                        if(mat[k][j]==1){
                            o1++;
                        }
                    }
                    for(int k=0;k<m;k++){
                        if(mat[i][k]==1){
                            o2++;
                        }
                    }
                }
                if(o1==1 && o2==1){
                    ans++;
                }
                
            }

        }
        return ans;
    }
};