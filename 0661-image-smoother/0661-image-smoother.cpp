class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r=img.size();
        int c=img[0].size();
        vector<vector<int>> ans(r,vector<int>(c));
        for (int i=0;i<r;i++){
            
            for (int j=0;j<c;j++){
                int sum=0;
                int b=0;
                sum+=img[i][j];
                b++;
                if(i-1>=0 ){
                    sum+=img[i-1][j];
                    b++;
                }
                if((i+1)<r ){
                    sum+=img[i+1][j];
                    b++;
                }
                if((j-1)>=0 ){
                    sum+=img[i][j-1];
                    b++;
                }
                if((j+1)<c ){
                    sum+=img[i][j+1];
                    b++;
                }
                if((j-1)>=0 && (i-1)>=0){
                    sum+=img[i-1][j-1];
                    b++;
                }
                if((j+1)<c && (i-1)>=0){
                    sum+=img[i-1][j+1];
                    b++;
                }
                if((j-1)>=0 && (i+1)<r){
                    sum+=img[i+1][j-1];
                    b++;
                }
                if((j+1)<c && (i+1)<r){
                    sum+=img[i+1][j+1];
                    b++;
                }
                ans[i][j]=sum/(b);
            }
        }
        return ans;
    }
};