class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> st;
        sort(nums.begin(),nums.end());
        
        for (int i=0;i<nums.size();i++){
            for (int j=nums.size()-1;j>i;j--){
                if(i>0 && nums[i]==nums[i-1]) continue;
                if(j<nums.size()-1 && nums[j]==nums[j+1]) continue;
                int k=i+1;
                int l=j-1;
                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector <int> aaa={nums[i],nums[j],nums[k],nums[l]};
                        st.push_back(aaa);
                        k++;
                        l--;
                        while(k<l && nums[k-1]==nums[k]) k++;
                        while(k<l && nums[l+1]==nums[l]) l--;
                    
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
                
                
            }
        }
        vector<vector<int>> anss(st.begin(),st.end());
        return anss;
    }
};