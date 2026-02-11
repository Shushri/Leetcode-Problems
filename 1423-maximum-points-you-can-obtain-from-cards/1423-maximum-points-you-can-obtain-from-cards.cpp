class Solution {
public:
    int maxScore(vector<int>& cP, int k) {
        int n=cP.size();
        int t=0;
        for(int i=0;i<k;i++){
            t+=cP[i];
        }
        int ans=t;
        for(int i=0;i<k;i++){
            t-=cP[k-i-1];
            t+=cP[n-i-1];
            ans=max(ans,t);
        }
        return ans;

    }
};