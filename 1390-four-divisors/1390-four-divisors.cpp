class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int j=0;j<nums.size();j++){
            vector<int> arr;
            for(int i=2;i*i<=nums[j];i++){
                if(nums[j]%i==0){
                    arr.push_back(i);
                }
            }
            if(arr.size()==1 && nums[j]/arr[0]!=arr[0]){
                
                sum+=(1+nums[j]+arr[0]+(nums[j]/arr[0]));
            }
        }
        return sum;
    }
};