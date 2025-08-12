class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map <char,int> mp1;
        unordered_map <char,int> mp2;
        for (int i=0;i<r.size();i++){
            mp1[r[i]]++;
        }
        for (int i=0;i<m.size();i++){
            mp2[m[i]]++;
        }
        for(auto ele:mp1){
            if(ele.second!=mp2[ele.first]){
                return false;
            }
        }
        return true;
    }
};