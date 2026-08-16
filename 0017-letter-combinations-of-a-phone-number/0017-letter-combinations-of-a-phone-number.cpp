class Solution {
public:
    void f(int ind,string s,vector<string>&ans,string &digits,unordered_map<char,string> &mpp){
        if(ind==digits.size()){
            ans.push_back(s);
            return ;
        }
        for(auto ch:mpp[digits[ind]]){
            f(ind+1,s+ch,ans,digits,mpp);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mpp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ans;
        f(0,"",ans,digits,mpp);
        return ans;
        
    }
};