class Solution {
public:
    int digsum(int num){
        int sm=0;
        while(num){
            int a=num%10;
            num=num/10;
            sm+=a;
        }
        return sm;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr=nums;
        auto lambda = [this](int n1,int n2){
            int d1=digsum(n1);
            int d2=digsum(n2);
            if(d1==d2){
                return n1<n2;
            }
            return d1<d2;
        };
        sort(nums.begin(),nums.end(),lambda);

        
        if(nums==arr) return 0;
        int swaps=0;

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]=i;
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=arr[i]){
                swaps++;
                int x=arr[i];
                int ind=mpp[nums[i]];
                swap(arr[i],arr[mpp[nums[i]]]);
                mpp[arr[i]]=i;
                mpp[x]=ind;
                
            }
        }
        return swaps;

    }
};

//6 4 2  nums
//2 6 4  arr
//2 0, 6 1, 4 2
//6 2 4
//6 4 2