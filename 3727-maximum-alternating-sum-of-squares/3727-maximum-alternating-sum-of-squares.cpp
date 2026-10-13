class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> new_nums(n);
        for(int i=0;i<n;i++){
            new_nums[i]=abs(nums[i]);
        }
        sort(new_nums.begin(),new_nums.end());
        long long ans=0;
        int l=0;
        int h=n-1;
        while(l<h){
            ans-=new_nums[l]*new_nums[l];
            cout<<ans<<" ";
            ans+=new_nums[h]*new_nums[h];
            cout<<ans<<" ";
            l++;
            h--;
            
        }
        if(l==h){
            ans+=new_nums[h]*new_nums[h];
        }
        return ans;
    }
};