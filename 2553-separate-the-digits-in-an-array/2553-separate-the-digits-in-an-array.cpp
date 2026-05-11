class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto ele:nums){
            string s=to_string(ele);
            for(char d:s){
                
                int nn=d-'0';
                ans.push_back(nn);
            }
        }
        return ans;
    }
};