class Solution {
public:
    int arrangeCoins(int n) {
        double ans=-0.5 + 0.5 * sqrt(1+8*(double)n);
        return ans;
        
    }
};

//