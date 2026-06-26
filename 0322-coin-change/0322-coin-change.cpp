class Solution {
public:
    int f(int ind,int amt, vector<int>& c,vector<vector<int >>& dp){
        
        if(ind==0){
            if(amt%c[ind]==0){
                return amt/c[ind];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int take=1e9;
        if(amt>=c[ind]) take=1+f(ind,amt-c[ind],c,dp);
        int nttake=f(ind-1,amt,c,dp);

        return dp[ind][amt]=min(take,nttake);
    }
    int coinChange(vector<int>& c, int amt) {
        
        int n=c.size();
        vector<vector<int >> dp(n,vector<int>(amt+1,-1));
        int ans= f(n-1,amt,c,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};