class Solution {
public:
    int ncr(int n, int r){
        int p=1;
        for(int i=1;i<=r;i++){
            p=p*(n-i+1)/i;
        }
        return p;
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> v(i+1);
            for(int j=0;j<=i;j++){
                v[j]=ncr(i,j);
            }
            ans.push_back(v);
        }
        return ans;
    }
};