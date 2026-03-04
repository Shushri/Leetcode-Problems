class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        double ans=0.0;
        vector<int> sm(n+m);
        int i=0;
        int j=0;
        int k=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                sm[k++]=nums1[i++];
            }
            else{
                sm[k++]=nums2[j++];
            }
        }
        while(i<n){
            sm[k++]=nums1[i++];
        }
        while(j<m){
            sm[k++]=nums2[j++];
        }

        sort(sm.begin(),sm.end());
        if((n+m)%2==1){
            int md=(n+m)/2;
            ans=sm[md];
        }
        else{
            int s1=(n+m)/2;
            int s2=s1-1;
            ans=(double)(sm[s1]+sm[s2])/2;
        }
        return ans;
       
    }
};