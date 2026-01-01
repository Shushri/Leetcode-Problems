class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        vector<int> ans;
        int c=1;
        for(int i=d.size()-1;i>=0;i--){
            ans.push_back((d[i]+c)%10);
            c=(d[i]+c)/10;

        }
        if(c!=0){
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};