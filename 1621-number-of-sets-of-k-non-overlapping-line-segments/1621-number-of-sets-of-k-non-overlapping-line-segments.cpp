
class Solution { 
public: 
    const int M=1e9+7; 
    
    int modulo(int a){ 
        return (a%M + M)%M; 
    } 
    
    int addValues(int a, int b){ 
        return modulo(modulo(a)+modulo(b)); 
    } 
    
    int multiplyValues(int a, int b){ 
        return modulo(modulo(a)*modulo(b)); 
    }
    
    int dp[1002][1002]; 
    int prefDp[1002][1002]; 
    
    int prefixWays(int n, int k){ 
        if(n<2) 
            return 0; 
        if(prefDp[n][k]!=-1) 
            return prefDp[n][k]; 
        return prefDp[n][k]=addValues(prefixWays(n-1,k),countWays(n,k)); 
    } 
    
    int countWays(int n, int k){ 
        if(k==1){ 
            return dp[n][k]=(n*(n-1))/2; 
        } 
        if(n==1) 
            return 0; 
        if(n-1==k) 
            return 1; 
        if(n-1<k) 
            return 0; 
        if(dp[n][k]!=-1) 
            return dp[n][k]; 
        
        int total=0; 
        total=addValues(total,countWays(n-1,k)); 
        total=addValues(total,prefixWays(n-1,k-1)); 
        
        return dp[n][k]=total; 
    } 
    
    int numberOfSets(int n, int k){ 
        memset(dp,-1,sizeof(dp)); 
        memset(prefDp,-1,sizeof(prefDp)); 
        return countWays(n,k); 
    } 
};

