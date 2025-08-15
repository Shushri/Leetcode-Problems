class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector <int> ans;
        int c=0;
        int n=digits.size();
        if(digits[n-1]==9){
            ans.push_back(0);
            c=1;
        }
        else{
            ans.push_back(digits[n-1]+1);
            c=0;
        }
        for (int i=n-2;i>=0;i--){
            
            if(digits[i]==9 && c==1){
                ans.push_back(0);
                c=1;
            }
            else{
                ans.push_back(c+digits[i]);
                c=0;
            }
        }
        if(c==1){
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};