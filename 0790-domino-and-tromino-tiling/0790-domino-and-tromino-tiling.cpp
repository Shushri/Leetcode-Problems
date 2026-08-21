class Solution {
public:
    long long MOD=1e9 + 7;
    long long f(int i, int n, vector<vector<long long>> &dp,bool possible){
        if(i==n){
            return possible==false;
        }
        if(i>n){
            return 0;
        }
        if(dp[i][possible]!=-1) return dp[i][possible];
        if(possible){
            return dp[i][possible]=(f(i+1,n,dp,false)+f(i+1,n,dp,true))%MOD;
        }
        else{
            return dp[i][possible]=(f(i+1,n,dp,false)+f(i+2,n,dp,false)+2*f(i+2,n,dp,true))%MOD;
        }
    }
    int numTilings(int n){
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        return f(0,n,dp,false);
    }

};