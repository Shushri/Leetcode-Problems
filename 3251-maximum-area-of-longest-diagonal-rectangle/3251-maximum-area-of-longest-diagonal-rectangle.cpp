class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        
        long long int mx=0;
        int mxar=0;
        for (int i=0;i<dim.size();i++){
            long long int d=(dim[i][0]*dim[i][0]+dim[i][1]*dim[i][1]);
            int ar=dim[i][0]*dim[i][1];
            if(d>mx || (d==mx && ar>mxar)){
                mxar=ar;
                mx=d;
            }
            

        }
        return mxar;
    }
};