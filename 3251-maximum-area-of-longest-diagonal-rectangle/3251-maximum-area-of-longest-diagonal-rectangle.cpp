class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        
        double mx=0.0;
        int mxar=0;
        for (int i=0;i<dim.size();i++){
            double d=sqrt(((double)dim[i][0]*(double)dim[i][0]+(double)dim[i][1]*(double)dim[i][1]));
            int ar=dim[i][0]*dim[i][1];
            if(d>mx || (fabs(d-mx)<1e-9 && ar>mxar)){
                mxar=ar;
                mx=d;
            }
            

        }
        return mxar;
    }
};