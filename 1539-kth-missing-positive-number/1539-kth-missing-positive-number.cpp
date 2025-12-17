class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0;
        int h=arr.size()-1;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(l==h){
                if(arr[mid]-(mid+1)>=k){
                    int diff=arr[mid]-(mid+1)-k+1;
                    ans=arr[mid]-diff;

                }
                else{
                    int diff=k-(arr[mid]-(mid+1));
                    ans=arr[mid]+diff;
                }
                break;
            }
            else if(arr[mid]-(mid+1)>=k){
                h=h-1;
            }
            else{
                l=l+1;
            }
        }
        return ans;
    }
};