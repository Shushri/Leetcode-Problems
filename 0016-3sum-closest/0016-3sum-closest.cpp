class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int diff=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sm=nums[i]+nums[j]+nums[k];
                int d=abs(sm-t);
                if(sm==t){
                    return t;
                }
                if(d<diff){
                    ans=sm;
                    diff=d;
                }
                if(sm>t){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
        
    }
};