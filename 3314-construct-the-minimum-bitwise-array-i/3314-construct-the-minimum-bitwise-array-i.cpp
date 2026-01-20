class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=-1;
            }
            else{
                //we look for trailing 1s and make the first 1 to 0 and keep other 1s as it is... 
                //example... 100110111 ... 
                //so the ans is 100110011
                int temp=nums[i];
                int c=0;
                while((temp&1)!=0){
                    temp=temp>>1;
                    c++;
                }
                cout<<c<<endl;
                int pp=1<<(c-1);
                nums[i]=nums[i]&(~pp);

            }
        }
        return nums;
    }
};