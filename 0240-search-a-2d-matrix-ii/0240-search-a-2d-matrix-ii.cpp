class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int r1=0;
        int c1=c-1;
        while(r1<=(r-1) && c1>=0){
            // cout<<r1<<" "<<c1<<endl;
            if(target==matrix[r1][c1]){
                return true;

            }
            else if(target<matrix[r1][c1]){
                if(c1==0){
                    return false;
                }
                else{
                    c1--;
                }
            }
            else{
                if(r1==(r-1)){
                    return false;
                }
                else{
                    r1++;
                }
            }
        }
        return false;

    }
};