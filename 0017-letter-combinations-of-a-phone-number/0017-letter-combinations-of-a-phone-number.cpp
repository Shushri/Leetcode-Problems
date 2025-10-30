class Solution {
public:
    vector<string> ans;
    
    void f(int ind, string &digits, string curr, unordered_map<char, string> &mpp) {
        if (ind == digits.size()) {
            ans.push_back(curr);
            return;
        }
        
        string letters = mpp[digits[ind]];
        for (char c : letters) {
            f(ind + 1, digits, curr + c, mpp);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // handle empty input
        
        unordered_map<char, string> mpp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        f(0, digits, "", mpp);
        return ans;
    }
};
