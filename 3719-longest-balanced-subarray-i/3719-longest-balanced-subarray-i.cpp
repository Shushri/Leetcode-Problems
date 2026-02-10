class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            int e=0;
            int o=0;
            unordered_map<int,int> mpp;
            for(int j=i;j<n;j++){
                if(mpp[nums[j]]==0){
                    if(nums[j]&1 ){
                        o++;
                    }
                    else{
                        e++;
                    }
                    mpp[nums[j]]++;
                }
                    
                if(o==e){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};