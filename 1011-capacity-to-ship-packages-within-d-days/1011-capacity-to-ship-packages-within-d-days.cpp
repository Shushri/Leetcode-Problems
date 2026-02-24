class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=*max_element(weights.begin(),weights.end());
        int h=0;
        int ans=0;
        for(int i=0;i<n;i++){
            h+=weights[i];
        }
        while(l<=h){
            int mid=l+(h-l)/2;
            int d=0;
            int p=0;
            for(int i=0;i<n;i++){
                if(p+weights[i]>mid){
                    if(p>0){
                        d++;
                        p=weights[i];
                    }
                }
                else{
                    p+=weights[i];
                }
            }
            if(p>0 && p<=mid){
                d++;
            }
            if(d<=days){
                h=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }

        }
        return ans;

    }
};