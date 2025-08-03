class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int sell=prices[n-1];
        int mx=0;
        int mn=prices[0];
        for (int i=1;i<n;i++){
            int diff=prices[i]-mn;
            mx=max(mx,diff);
            mn=min(mn,prices[i]);
        }
        return mx;
    }
};