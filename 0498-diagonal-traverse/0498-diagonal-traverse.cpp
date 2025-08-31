class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<int> ans;
        for(int i=0;i<(r+c-1);i++){
            
            if(i%2==0){
                int r1=i<r?i:(r-1);
                int c1=i-r1;
                while(r1>=0 && c1<c){
                    ans.push_back(mat[r1--][c1++]);
                }
            }
            else{
                int c1=i<c?i:c-1;
                int r1=i-c1;
                while(r1<r && c1>=0){
                    ans.push_back(mat[r1++][c1--]);
                }
            }
            
            

        }
        
        
        return ans;

    }
};