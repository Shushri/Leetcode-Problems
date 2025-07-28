class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        int low = 0, high = a.size() - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (a[mid] == t) {
                return mid;
            } else if (a[mid] < t) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
