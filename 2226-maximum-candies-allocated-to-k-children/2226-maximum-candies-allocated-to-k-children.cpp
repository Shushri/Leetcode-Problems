class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int mxel=*max_element(candies.begin(),candies.end());
        int l=1;
        int h=mxel;
        int ans=0;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            long long tt=0;
            for(int i=0;i<n;i++){
                tt+=candies[i]/mid;

            }
            if(tt>=k){
                ans=mid;
                l=mid+1;

            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};