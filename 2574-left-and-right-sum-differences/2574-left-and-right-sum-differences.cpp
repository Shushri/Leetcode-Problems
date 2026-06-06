class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return {0};
        }
        vector<long long> presm(n);
        vector<long long> postsm(n);
        presm[0]=nums[0];
        postsm[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            presm[i]=presm[i-1]+nums[i];
            postsm[n-i-1]=nums[n-i-1]+postsm[n-i];
        }
        // for(auto ele:presm){
        //     cout<<ele<<" ";
        // }
        // cout<<endl;
        //         for(auto ele:postsm){
        //     cout<<ele<<" ";
        // }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=postsm[i+1];
            }
            else if(i==n-1){
                ans[i]=presm[i-1];
            }
            else{
                ans[i]=abs(presm[i-1]-postsm[i+1]);
            }
        }
        return ans;
    }
};