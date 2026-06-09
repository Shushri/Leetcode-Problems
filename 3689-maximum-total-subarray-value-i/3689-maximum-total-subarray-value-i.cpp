class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn=*min_element(nums.begin(),nums.end());
        long long mx=*max_element(nums.begin(),nums.end());
        long long p=mx-mn;
        p=p*k;
        return p;

    }
};