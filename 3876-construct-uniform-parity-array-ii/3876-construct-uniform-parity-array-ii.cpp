class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int e=0;
        int o=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) e++;
            else o++;
        }        
        if(e==n || o==n) return true;

        int sm=*min_element(nums1.begin(),nums1.end());
        if(sm%2==0) return false;
        return true;
    }
};
//odd even ke case me we can only make all odd
//count even and odd if even=n or odd=n then true
//we can sort the array
// if first element is even then false