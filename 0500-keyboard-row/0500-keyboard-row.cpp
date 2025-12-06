class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a="qwertyuiop";
        string b="asdfghjkl";
        string c="zxcvbnm";
        vector<string> ans;
        for(auto word:words){
            int aa=1;
            int bb=1;
            int cc=1;
            
            for(auto i:word){
                char p=tolower(i);
                if(a.find(p)==string::npos){
                    aa=0;
                    break;
                }
            }
            for(auto i:word){
                char p=tolower(i);
                if(b.find(p)==string::npos){
                    bb=0;
                    break;
                }
            }
            for(auto i:word){
                char p=tolower(i);
                if(c.find(p)==string::npos){
                    cc=0;
                    break;
                }
            }
            if(aa==1 || bb==1 || cc==1){
                ans.push_back(word);
            }
        }
        return ans;

    }
};