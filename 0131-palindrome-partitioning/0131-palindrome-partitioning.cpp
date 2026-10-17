class Solution {
public:
    bool ispalindrome(string s, int l, int h){
        while(l<=h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    void f(int ind, string &s,vector<string> arr, vector<vector<string>> &ans ){
        if(ind == s.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s,ind,i)){
                arr.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,arr,ans);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;
        int n=s.size();
        f(0,s,arr,ans);
        return ans;
    }
};