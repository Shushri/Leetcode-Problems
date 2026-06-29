class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<int> mns(n);
        vector<int> mxs(n);
        mns[0]=p[0];
        mxs[n-1]=p[n-1];
        for(int i=1;i<n;i++){
            mns[i]=min(mns[i-1],p[i]);
        }
        for(int i=n-2;i>=0;i--){
            mxs[i]=max(mxs[i+1],p[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,mxs[i]-mns[i]);
        }
        return ans;

    }
};