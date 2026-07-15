class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int ev=(n*(2*2+(n-1)*2))/2;
        int od=(n*(2*1+(n-1)*2))/2;
        return __gcd(ev,od);
    }
};