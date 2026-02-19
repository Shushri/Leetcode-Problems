class Solution {
public:
    int minDays(vector<int>& bD, int m, int k) {
        int n=bD.size();
        long long p=(long)m*(long)k;
        if(n<p){
            return -1;
        }
        int l=*min_element(bD.begin(),bD.end());
        int h=*max_element(bD.begin(),bD.end());
        int ans=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            int c=0;
            int temp=0;
            
            for(int i=0;i<n;i++){
                if(bD[i]<=mid){
                    c++;
                }
                else{
                    temp+=c/k;
                    c=0;
                }
            }
            temp+=c/k;
            if(temp>=m){
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
    }
};