class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string> ans;
        string s="";
        for(int i=0;i<m;i++){
            s+='.';
        }
        ans.push_back(s);
        s="";
        for(int i=0;i<m;i++){
            if(i==m-1){
                s+='.';
            }
            else{
                s+='#';
            }
        }
        for(int i=1;i<n;i++){
            ans.push_back(s);
        }
        return ans;

    }
};