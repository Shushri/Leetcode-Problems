class Solution {
public:
    int f(int n1,int n2,string &s1,string &s2,vector<vector<int>> &dp){
        if(n1<0 || n2<0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(s1[n1]==s2[n2]) return 1+f(n1-1,n2-1,s1,s2,dp);
        
        return dp[n1][n2]=0+max(f(n1-1,n2,s1,s2,dp),f(n1,n2-1,s1,s2,dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return f(n1-1,n2-1,text1,text2,dp);
    }
};