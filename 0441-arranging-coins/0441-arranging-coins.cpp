class Solution {
public:
    int arrangeCoins(int n) {
        int c=1;
        int ans=0;
        while (n>0){
            if(n>=c){
                ans++;
            }
            n-=c;
            c++;
        }
        return ans;

        
    }
};