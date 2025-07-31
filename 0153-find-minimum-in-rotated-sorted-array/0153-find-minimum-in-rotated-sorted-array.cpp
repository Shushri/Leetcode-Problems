class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high){
              int mid=(low+high)/2;
                if(a[low]<a[high]){
                    ans=min(a[low],ans);
                    break;    
                }
              if(a[low]<=a[mid]){
                ans=min(ans,a[low]);
                low=mid+1;
              }  
              else if(a[high]>=a[mid]){
                ans=min(ans,a[mid]);
                high=mid-1;
              }

        }        
        return ans;
        
    }
};