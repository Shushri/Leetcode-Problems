class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       long long tot=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        tot+=nums[i];
       }     
       
       int rem=tot%p;
        if(rem==0){
            return 0;
        }
        unordered_map <int ,int> mpp;
        mpp[0]=-1;
        int ans=INT_MAX;
        long long pref=0;
        for(int i=0;i<n;i++){
            pref+=nums[i];
            int cur=pref%p;
            int target=(cur-rem+p)%p;
            if(mpp.count(target)!=0){
                int j=mpp[target];
                ans=min(ans,i-j);
            }
            mpp[cur]=i;
        }
        if(ans>=n) return -1;
        return ans;
        

    }
};
//(total-x)%p==0
//x%p==rem
//5%3=2
