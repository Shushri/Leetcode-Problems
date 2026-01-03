class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1e9+7;
        //let pattern p1=010
        //let pattern p2=012
        long p1=6;
        long p2=6;
        for(int i=2;i<=n;i++){
            long long newp1=((3*p1)%MOD+(2*p2)%MOD)%MOD;
            long long newp2=((2*p1)%MOD+(2*p2)%MOD)%MOD;
            p1=newp1;
            p2=newp2;
        }
        return (p1+p2)%MOD;
    }
};