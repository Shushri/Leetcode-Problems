class Solution {
public:
    int reverseBits(int n) {
        int p=0;
        for(int i=0;i<32;i++){
           p=p<<1;
           p=(1&n)|p;
           n=n>>1;
        }
        return p;
    }
};