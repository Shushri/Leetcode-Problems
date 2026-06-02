class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int c=t-nums[i];
            auto it=find(nums.begin(),nums.end(),c);
            if(it!=nums.end()){
                if((it-nums.begin())!=i){
                    int j=it-nums.begin();
                    return {i,j};
                }
            }
        }
        return {0,0};

    }
};