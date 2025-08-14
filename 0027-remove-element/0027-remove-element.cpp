class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=0;
        int n=nums.size();
        int c=0;
        for (int i=0;i<n;i++){
            if(nums[i]==val){
                c++;
            }
        }
        while(i<n && j<n){
            if(nums[j]==val){
                j++;
            }
            else if(nums[j]!=val && nums[i]!=val){
                i++;j++;
            }
            else{
                swap(nums[j],nums[i]);
                i++;
                j++;
            }
        }
        return n-c;
    }
};