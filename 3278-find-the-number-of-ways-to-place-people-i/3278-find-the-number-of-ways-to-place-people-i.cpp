class Solution {
public:
    static bool comp(const vector<int>& p1, const vector<int>& p2){
    if (p1[0] == p2[0]) return p1[1] > p2[1]; 
    return p1[0] < p2[0];
}

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        
        for(auto i : points){
            cout<<i[0]<<" "<<i[1]<<"  ";
        }

        int cnt=0;

        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                if(points[j][0]<points[i][0] || points[j][1]>points[i][1]){
                    continue;
                }
                int b=0;
                for(int k=i+1;k<j;k++){
                    if(points[k][0]>=points[i][0] && points[k][0]<=points[j][0] && points[k][1]<=points[i][1] && points[k][1]>=points[j][1]){
                        b=1;
                        break;
                    }
                }
                if(b==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};