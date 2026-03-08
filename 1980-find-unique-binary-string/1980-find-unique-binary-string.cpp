class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s="";
        int n=nums.size();
        for(int i=0;i<n;i++){
            s+='0';
        }        
        if(find(nums.begin(), nums.end(), s) == nums.end()){
            return s;
        }
        for(int i=1;i<=n;i++){
            string ss=s;
            ss[i-1]='1';
            if(find(nums.begin(), nums.end(), ss) == nums.end()){
                return ss;
            }
        }
        return s;
    }
};