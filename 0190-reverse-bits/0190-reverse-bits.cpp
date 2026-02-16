class Solution {
public:
    int reverseBits(int n) {
        int p=0;
        for(int i=0;i<32;i++){
            if((n&1)==1){
                p=p<<1;
                p=p|1;
                
                n=n>>1;
            }
            else{
                p=p<<1;
                p=p|0;
                
                n=n>>1;
            }
        }
        return p;
    }
};