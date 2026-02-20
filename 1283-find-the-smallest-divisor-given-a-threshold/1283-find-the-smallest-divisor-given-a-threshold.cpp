class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int ans=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            long long pp=0;
            for(int i=0;i<n;i++){
                pp+=(nums[i]+mid-1)/mid;
            }
            if(pp<=threshold){
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};