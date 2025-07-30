class Solution {
public:
    bool search(vector<int>& a, int t) {
        int low=0;
        int n=a.size();
        int high= n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]==t){
                return true;
            }    

            if(a[low]==a[mid] && a[mid]==a[high]  ){
                low++;
                high--;
                continue;
            }

            if(a[low]<=a[mid]){
                if(t<a[mid] && t>=a[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(t>a[mid] && t<=a[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};