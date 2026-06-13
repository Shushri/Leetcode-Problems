class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
        string ans="";
        for(int i=0;i<words.size();i++){
            string s=words[i];
            int tot=0;
            for(auto c:s){
                int ind=c-'a';
                tot+=w[ind];
            }
            tot=tot%26;
            tot=25-tot;
            ans+=('a'+tot);
        }
        return ans;
    }
};