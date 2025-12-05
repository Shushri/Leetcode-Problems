class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        long long sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            nums[i]=sm;
        }
        int c=0;
        for(int i=1;i<n;i++){
            long long a=nums[i-1];
            long long b=nums[n-1]-nums[i-1];
            long long diff=abs(a-b);
            if(diff%2==0){
                c++;
            } 
        }
        return c;
    }
};
//[10,20,23,30,36]