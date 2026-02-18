class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hr) {
        int n=piles.size();
        int mxel=*max_element(piles.begin(),piles.end());
        int l=1;
        int h=mxel;
        int ans=mxel;
        while(l<=h){
            int mid=l+(h-l)/2;
            long long tt=0;
            for(int i=0;i<n;i++){
                tt+=(piles[i]+mid-1)/mid;

            }
            if(tt<=hr){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};