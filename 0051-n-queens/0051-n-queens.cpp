class Solution {
public:
    void f(int col,int n, vector<vector<string>> &ans,vector<string> &arr,vector<int>& left,vector<int> &ddown,vector<int> &dup ){

        if(col==n){
            ans.push_back(arr);
            return;
        }

        for(int row=0;row<n;row++){
            if(left[row]==0 && ddown[row+col]==0 && dup[(n-1)+(col-row)]==0){
                arr[row][col]='Q';
                left[row]=1;
                ddown[row+col]=1;
                dup[(n-1)+(col-row)]=1;
                f(col+1,n,ans,arr,left,ddown,dup);
                arr[row][col]='.';
                left[row]=0;
                ddown[row+col]=0;
                dup[(n-1)+(col-row)]=0;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> arr(n,string(n,'.'));
        vector<int> left(n,0);
        vector<int> ddown(2*n-1,0);
        vector<int> dup(2*n-1,0);
        f(0,n,ans,arr,left,ddown,dup);

        return ans;
    }
};