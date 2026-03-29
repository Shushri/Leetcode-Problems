class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]=true;
        }
        for(int i=0;i<n;i++){
            if(mpp.count(nums[i]-1)>0){
                mpp[nums[i]]=false;
            }
        }
        int ans=0;
        for(auto ele:mpp){
            if(ele.second==true){
                int j=0;
                while(true){
                    if(mpp.count(ele.first+j)>0){
                        j++;
                    }
                    else{
                        break;
                    }
                }
                ans=max(ans,j);
            }
        }
        return ans;
    }
};