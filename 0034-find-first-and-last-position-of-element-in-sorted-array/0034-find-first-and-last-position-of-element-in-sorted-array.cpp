class Solution {
public:
    int f_occ(vector<int>& arr,int n,int t){
        int low=0; int high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==t){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]>t){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return first;
    }
    int l_occ(vector<int>& arr,int n,int t){
        int low=0; int high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==t){
                last=mid;
                low=mid+1;
            }
            else if(arr[mid]>t){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        return {f_occ(nums,n,target),l_occ(nums,n,target)};
    }
};