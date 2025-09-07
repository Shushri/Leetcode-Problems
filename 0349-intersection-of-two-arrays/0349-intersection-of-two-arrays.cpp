class Solution {
public:
    vector<int> intersection(vector<int>& a1, vector<int>& a2) {
        unordered_set<int> st1(a1.begin(),a1.end());
        unordered_set<int> st2(a2.begin(),a2.end());
        vector<int> ans;
        for(auto ele:st1){
            if(st2.count(ele)){
                ans.push_back(ele);
            }
        }
        return ans;
    }
};