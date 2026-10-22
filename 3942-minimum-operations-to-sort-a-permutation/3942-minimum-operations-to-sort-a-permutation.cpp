class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int ind=0;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                cnt++;
            }
            if(nums[i]==0){
                ind=i;
            }
        }
        cout<<cnt<<endl;
        if(cnt==n-1 ){
            return 0;
        }
        if(cnt==0){
            return 1;
        }
        if(cnt==n-2){
            if(nums[0]>nums[n-1]){
                int x1=n-ind+2;
                int x2=ind;
                ans=min(x1,x2);
            }

        }
        if(cnt==1){
            if(nums[0]<nums[n-1]){
                int x1=ind+2;
                int x2=n-ind;
                ans=min(x1,x2);
            }
        }

        if(ans==INT_MAX) return -1;
        return ans;
    }
};