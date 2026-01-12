class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int x=points[0][0];
        int y=points[0][1];

        for(int i=1;i<points.size();i++){
            
            int xi=points[i][0];
            int yi=points[i][1];
            int d1=abs(x-xi);
            int d2=abs(y-yi);
            ans+=d1+d2-min(d1,d2);
            x=xi;
            y=yi;
            


        }
        return ans;
    }
};