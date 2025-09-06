class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        vector<int> stt;
        for(auto ele: st){
            cout<<ele <<" ";
            stt.push_back(ele);
        }
        cout<<endl;
        int mx=1;
        int c=1;
        for(int i=1;i<stt.size();i++){
            if((long long)stt[i]-(long long)stt[i-1]==1){
                c++;
            }
            else{
                mx=max(mx,c);
                c=1;
            }
        }
        mx=max(mx,c);
        return mx;
    }
};