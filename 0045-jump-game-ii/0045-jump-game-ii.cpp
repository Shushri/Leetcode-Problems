class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0; 
        int n=nums.size();
        int jmp=0;
        while(r<n-1){
            int mx=0;
            for (int i=l;i<=r;i++){
                mx=max(mx,nums[i]+i);
                
            }
            l=r+1;
            r=mx;
            jmp++;
        }
        return jmp;
    }
};