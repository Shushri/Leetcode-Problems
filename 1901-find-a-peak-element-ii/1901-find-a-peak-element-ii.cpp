class Solution {
public:
    int findmxind(int c,vector<vector<int>>& mat){
        int n=mat.size();
        int mx=INT_MIN;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(mat[i][c]>mx){
                ans=i;
                mx=mat[i][c];
            }
        }
        return ans;
        
    } 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int ind=findmxind(mid,mat);
            int left=mid-1>=0?mat[ind][mid-1]:-1;
            int right=mid+1<m?mat[ind][mid+1]:-1;
            if(mat[ind][mid]>left && mat[ind][mid]>right){
                return {ind,mid};
            }
            else if(mat[ind][mid]>left){
                l=mid+1;
            }
            else{
                h=mid-1;
            }

        }
        return {-1,-1};

    }
};