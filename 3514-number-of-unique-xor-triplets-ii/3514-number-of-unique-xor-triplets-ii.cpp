class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int mx = 2048;

        vector<int> xr2(mx, 0);
        vector<int> xr3(mx, 0);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                xr2[nums[i] ^ nums[j]] = 1;
            }
        }

        for (int x = 0; x < mx; x++) {
            if (!xr2[x]) continue;
            for (int v : nums) {
                xr3[x ^ v] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < mx; i++){
            if(xr3[i]) count++;
        }

        return count;
    }
};