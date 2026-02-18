class Solution {
public:
    bool hasAlternatingBits(int n) {
        int o=0;
        int z=0;
        while(n){
            if(n&1){
                if(o==0){
                    o=1;
                }
                else{
                    return false;
                }
                z=0;
            }
            else{
                if(z==0){
                    z=1;
                }
                else{
                    return false;
                }
                o=0;
            }
            n=n>>1;
        }
        return true;
    }
};