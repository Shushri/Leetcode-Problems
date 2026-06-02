class Solution {
public:
    int earliestFinishTime(vector<int>& lT, vector<int>& lD, vector<int>& wT, vector<int>& wD) {
        int n=lT.size();
        int m=wT.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(lT[i]<=wT[j]){
                    int t=lT[i]+lD[i];
                    if(t>=wT[j]){
                        t+=wD[j];
                    }
                    else{
                        t=wT[j]+wD[j];
                    }
                    ans=min(ans,t);
                }
                else{
                    int t=wT[j]+wD[j];
                    if(t>=lT[i]){
                        t+=lD[i];
                    }
                    else{
                        t=lT[i]+lD[i];
                    }
                    ans=min(ans,t);
                }
            }
        }
        return ans;
    }
};