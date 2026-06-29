class Solution {
public:
    bool f(int i,int j,string &s, string &p,vector<vector<int>> &dp ){
        if(i<0 && j<0 ) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int pos=0;pos<=j;pos++){
                if(p[pos]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        if(p[j]=='*') return dp[i][j]=f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};