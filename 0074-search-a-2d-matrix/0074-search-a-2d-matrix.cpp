class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int n=r*c;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int r1=mid/c;
            int c1=mid%c;
            if(matrix[r1][c1]==target){
                return true;
            }
            else if(target<matrix[r1][c1]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;

    }
};