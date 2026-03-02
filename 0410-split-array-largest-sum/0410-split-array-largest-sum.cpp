class Solution {
public:
    int splitArray(vector<int>& nums, int p) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int k=0;
            int mx=0;
            int t=0;
            for(int i=0;i<n;i++){
                if(k+nums[i]<=mid){
                    k=k+nums[i];
                }
                else{
                    t++;
                    mx=max(mx,k);
                    
                    k=nums[i];
                }
            }
            t++;
            if(t>p){
                
                l=mid+1;
            }
            else{
                ans=mid;
                h=mid-1;
            }
            
        }
        return ans;
    }
};
//5 to 15
//mid=10
//10 5
//5 to 9
//mid=7
//6 9
//8 to 9
//mid=8
//6 9
//
