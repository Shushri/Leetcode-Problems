class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n=h.size();
        sort(h.begin(),h.end());
        int p=0;
        long long int sm=0;
        for(int i=n-1;i>=(n-k);i--){
            if((h[i]-p)>0){
                sm+=(h[i]-p);
            }
            p++;
        }
        return sm;
    }
};