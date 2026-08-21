class Solution {
public:
    long long MOD = 1e9 + 7;
    
    int numTilings(int n) {
        
        long long a1 = 0; // possible
        long long b1 = 1; // not possible
        long long a2 = 0;
        long long b2 = 0;

        for(int i = n - 1; i >= 0; i--) {
            long long temp1 = (a1 + b1) % MOD;
            long long temp2 = (b1 + b2 + 2LL * a2) % MOD;
            
            a2 = a1;
            b2 = b1;

            a1 = temp1; // possible
            b1 = temp2; // not possible
        }

        return b1;
    }
};