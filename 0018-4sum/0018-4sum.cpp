class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set <vector <int>> s;
        sort (nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-3; i++) {
            for (int j = n-1; j > i; j--) {
                int k = i+1, l = j-1;
                while (k < l) {
                    if ((long long int) nums[i] + nums[j] + nums[k] + nums[l] > target) {
                        l--;
                    } else if ((long long int) nums[i] + nums[j] + nums[k] + nums[l] < target) {
                        k++;
                    } else {
                        s.insert({(int)nums[i],(int) nums[j],(int) nums[k],(int) nums[l]});
                        k++; l--;
                    }
                }
            }
        }
        vector <vector <int>> ans (s.begin(), s.end());
        return ans;
    }
};