class Solution {
public:
    vector<string> ans;
    void f(int ind ,string digits,string ss,unordered_map<char,string> mpp){
        if(ss.size()==digits.size()){
            ans.push_back(ss);
            return;
        }
        for(int i=0;i<mpp[digits[ind]].size();i++){
            ss+=mpp[digits[ind]][i];
            f(ind+1,digits,ss,mpp);
            ss.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mpp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        f(0,digits,"",mpp);
        return ans;
        
    }
};