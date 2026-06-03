class Solution {
public:
    int earliestFinishTime(vector<int>& lT, vector<int>& lD, vector<int>& wT, vector<int>& wD) {
        int n=lT.size();
        int m=wT.size();
        int ans=INT_MAX;
        int mn_land=INT_MAX;
        for(int i=0;i<n;i++){
            mn_land=min(mn_land,lT[i]+lD[i]);
        }
        int mn_wat=INT_MAX;
        for(int i=0;i<m;i++){
            if(wT[i]<=mn_land){
                mn_wat=min(mn_wat,mn_land+wD[i]);
            }
            else{
                mn_wat=min(mn_wat,wT[i]+wD[i]);
            }
        }

        int mn_wat2=INT_MAX;
        for(int i=0;i<m;i++){
            mn_wat2=min(mn_wat2,wT[i]+wD[i]);
        }
        int mn_land2=INT_MAX;
        for(int i=0;i<n;i++){
            if(lT[i]<=mn_wat2){
                mn_land2=min(mn_land2,mn_wat2+lD[i]);
            }
            else{
                mn_land2=min(mn_land2,lT[i]+lD[i]);
            }
        }
        ans=min(mn_land2,mn_wat);
        return ans;
    }
};