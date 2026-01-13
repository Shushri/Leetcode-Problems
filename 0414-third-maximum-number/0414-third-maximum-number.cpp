class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int t=st.size()-3+1;
        if(st.size()<3){
            t=st.size();
        }
        int p=1;
        for(auto ele:st){
            if(p==t){
                return ele;
            }
            p++;
        }
        return -1;
    }
};