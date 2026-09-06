class Solution {
public:
    int f(int i,int j,string &s, string &t,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        return dp[i][j]=f(i-1,j,s,t,dp); 
    }
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2,-1));
        return f(n1-1,n2-1,s,t,dp);
    }
};
//needs dp
//need to see the indexes of both
//if equal chars at indexes... we will move both pointers or we can move for s only
//nt eql ... move only for s
//if we reach the end of t then add 1
//if we reach end of s then 0;