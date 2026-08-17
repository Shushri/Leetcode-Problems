class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        int n=inv.size();
        sort(inv.begin(),inv.end());
        vector<vector<int>> ans;
        ans.push_back(inv[0]);
        int j=0;
        for(int i=1;i<n;i++){
            if(inv[i][0]>=ans[j][1]){
                ans.push_back(inv[i]);
                j++;
            }
            else{
                if(inv[i][1]<ans[j][1]){
                    ans[j][1]=inv[i][1];

                }
            }
        }
        return n-ans.size();
    }
};