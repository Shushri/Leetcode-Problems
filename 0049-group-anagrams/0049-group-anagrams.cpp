class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<string,vector<string>> mpp;
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(strs[i]);

        }
        vector<vector<string>> ans;
        for(auto a:mpp){
            ans.push_back(a.second);
        }
        return ans;

    }
};