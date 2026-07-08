class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        int mx=*max_element(c.begin(),c.end());
        vector<bool> ans(c.size());
        for(int i=0;i<c.size();i++){
            if(c[i]+ec>=mx){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};