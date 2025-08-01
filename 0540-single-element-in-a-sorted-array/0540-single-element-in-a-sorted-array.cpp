class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        int low=0;
        int high=n-1;
        int ans=a[0];
        if(n==1){
            return a[0];
        }
        else if(a[0]!=a[1]){
            return a[0];
        }
        else if(a[n-1]!=a[n-2]){
            return a[n-1];
        }

        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid-1]!=a[mid] && a[mid]!=a[mid+1]){
                return a[mid];
            }
            else if((mid%2==0 && a[mid]==a[mid+1]) || (mid%2==1 && a[mid]==a[mid-1]) ){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
                
        }
        return ans;
    }
};