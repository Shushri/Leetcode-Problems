class Solution {
public:
    int maxProfit(vector<int>& p) {
      int mx=0;
      int n=p.size();
      int mn=INT_MAX;
      for(int i=0;i<n;i++){
        mn=min(mn,p[i]);
        mx=max(mx,p[i]-mn);
      }
      return mx;
    }
};