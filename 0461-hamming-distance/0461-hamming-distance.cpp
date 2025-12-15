class Solution {
public:
    int hammingDistance(int x1, int y1) {
        long long x=x1;
        long long y=y1;
        int c=0;
        long long p=x ^ y;
        while(p){
            p=p & (p-1);
            c++;
        }
        return c;
    }
};