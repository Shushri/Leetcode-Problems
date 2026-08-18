class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int c1=0;
        int c2=0;
        int n= nums.size();
        int a=nums[0];
        int b=nums[n-1];
        if(k==n) return *max_element(nums.begin(),nums.end());
        if(k==1) {
            unordered_map<int,int> mpp;
            for(auto ele:nums){
                mpp[ele]++;
            }
            
            int ans=INT_MIN;
            for(auto ele:mpp){
                if(ele.second==1){
                    ans=max(ans,ele.first);
                }
            }
            if(ans==INT_MIN) return -1;
            return ans;
        }
        for(auto el: nums){
            if(el==a) c1++;
            if(el==b) c2++;
        }
        if(c1==1 && c2==1) return max(a,b);
        if(c1==1) return a;
        if(c2==1) return b;
        return -1;
        
    }
};