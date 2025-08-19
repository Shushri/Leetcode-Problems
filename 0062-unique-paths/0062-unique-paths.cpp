class Solution {
public:
    
    int uniquePaths(int m, int n) {
          int r=min(m-1,n-1);
          int q=(m+n-2);
          long long ans=1;
          for(int i=1;i<=r;i++){
            ans=ans*(q-r+i)/i;
          }
          return (int)ans;
    }
};