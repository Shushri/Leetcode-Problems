class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> arr;
        int n=nums.size();
        int i=0;
        for(i;i<n;i++){
            if(nums[i]==1){
                break;
            }
        }
        int oc=0;
        int zc=0;
        for(i;i<n;i++){
            if(nums[i]==1){
                if(zc>0) {arr.push_back(zc);zc=0;}
                oc++;
            }
            else{
                if(oc>0) {arr.push_back(oc);oc=0;}
                zc++;
            }
        }
        if(oc>0) {arr.push_back(oc);oc=0;}
        if(zc>0) {arr.push_back(zc);zc=0;}
        int mx=0;
        if(arr.empty()) return 0;
        if(arr.size()==1 && arr[0]==n) return n-1;
        for(int j=0;j<arr.size();j++){
            if(j%2==1){
                if(arr[j]==1 && j<(arr.size()-1)){
                    mx=max(mx,arr[j+1]+arr[j-1]);
                }

            }
            else{
                mx=max(mx,arr[j]);
            }
        }

        return mx;


    }
};