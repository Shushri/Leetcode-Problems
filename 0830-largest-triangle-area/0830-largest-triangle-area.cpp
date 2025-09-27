class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        
        double ar=0.0;
        int n=points.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    double aa=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                    double a=pow(aa,0.5);
                    
                    double bb=pow(points[k][0]-points[j][0],2)+pow(points[k][1]-points[j][1],2);
                    double b=pow(bb,0.5);
                    
                    double cc=pow(points[i][0]-points[k][0],2)+pow(points[i][1]-points[k][1],2);
                    double c=pow(cc,0.5);
                    
                    double sp=(a+b+c)/2;
                    
                    double arrr=sp*(sp-a)*(sp-b)*(sp-c);
                    double ar1=pow(arrr,0.5);
                    
                    ar=max(ar,ar1);
                }
            }
        }
        return ar;
    }
};