class Solution {
public:
    int lower_b(vector<int>& nums,int n, int t){
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=t){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
            
    }

    int upper_b(vector<int>& nums,int n, int t){
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>t){
                ans=mid;
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lower_b(nums,n,target);
        if(lb==n || nums[lb]!=target){
            return {-1,-1};
        }
        return {lb,upper_b(nums,n,target)-1};

    }
};