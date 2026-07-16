class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> gcd(n);
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            gcd[i]=__gcd(mx,nums[i]);

        }
        sort(gcd.begin(),gcd.end());
        int i=0;int j=n-1;
        long long sm=0;
        while(i<j){
            sm+=__gcd(gcd[i++],gcd[j--]);
        }
        return sm;

    }
};