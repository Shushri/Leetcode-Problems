class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        // Handle negative exponent
        if (n < 0) {
            x = 1 / x;
            // To handle edge case when n == INT_MIN
            if (n == INT_MIN) {
                return x * myPow(x, -(n + 1));
            }
            n = -n;
        }

        double half = myPow(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};
