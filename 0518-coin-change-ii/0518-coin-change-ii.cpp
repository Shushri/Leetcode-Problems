class Solution {
public:
    int f(int ind,int amt, vector<int>& c,vector<vector<int >>& dp){
        
        if(ind==0){
            if(amt%c[ind]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int take=0;
        if(amt>=c[ind]) take=f(ind,amt-c[ind],c,dp);
        int nttake=f(ind-1,amt,c,dp);

        return dp[ind][amt]=take+nttake;
    }
    int change(int amt, vector<int>& c) {
        
        int n=c.size();
        vector<vector<int >> dp(n,vector<int>(amt+1,-1));
        int ans= f(n-1,amt,c,dp);
        
        return ans;
    }
};