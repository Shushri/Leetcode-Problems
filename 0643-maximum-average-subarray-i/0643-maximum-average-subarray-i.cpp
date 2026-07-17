class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<long long > pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int p=0;
        double mx=(double)pref[k-1]/k;
        for(int i=k;i<n;i++){
            double tt=(double)(pref[i]-pref[p])/(double)k;
            mx=max(mx,tt);
            p++;
        }
        return mx;
    }
};