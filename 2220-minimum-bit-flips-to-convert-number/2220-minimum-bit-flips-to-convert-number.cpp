class Solution {
public:
    int minBitFlips(int s, int g) {
        long long p=s ^ g;
        int c=0;
        while(p){
            p=p&(p-1);
            c++;
        }
        return c;
    }
};