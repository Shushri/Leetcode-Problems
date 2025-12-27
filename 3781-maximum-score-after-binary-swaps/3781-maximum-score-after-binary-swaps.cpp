class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long sm=0;
        int n=nums.size();
        priority_queue <int> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(s[i]=='1'){
                sm+=pq.top();
                pq.pop();
            }
        }
        
        return sm;
    }
};