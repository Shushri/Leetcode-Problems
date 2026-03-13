
class Solution {
public:
    long long minNumberOfSeconds(long long mountainHeight, vector<int>& workerTimes) {
        long long left = 1;
        long long right = 1e16;
        long long answer = right;

        while (left <= right) {
            long long midTime = left + (right - left) / 2;
            long long totalHeight = 0;

            for (long long i = 0; i < workerTimes.size() && totalHeight < mountainHeight; i++) {
                long long timePerUnit = workerTimes[i];

                long double value = (long double)midTime / timePerUnit * 2.0 + 0.25;
                long long units = (long long)(sqrt(value) - 0.5);

                totalHeight += units;
            }

            if (totalHeight >= mountainHeight) {
                answer = midTime;
                right = midTime - 1;
            } else {
                left = midTime + 1;
            }
        }

        return answer;
    }
};