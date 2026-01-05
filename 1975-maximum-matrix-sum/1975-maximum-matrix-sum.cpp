class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int neg=0;
        int z=0;
        int mn=abs(matrix[0][0]);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    z++;
                }
                if(matrix[i][j]<0){
                    neg++;
                }
                sum+=abs(matrix[i][j]);
                mn=min(mn,abs(matrix[i][j]));
            }
        }
        if(z>0){
            return sum;
        }
        if(neg%2==0){
            return sum;
        }
        
        return sum-2*mn;
        
    }
};