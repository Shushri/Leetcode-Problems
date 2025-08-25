class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        for (long long int i=1;i*i<=x;i++){
            ans=i;
        }
        return ans;
    }
};