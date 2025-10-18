class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;
    void f(int ind,int t,vector<int> &cnd,int n){
        if(ind==n){
            if(t==0){
                ans.push_back(arr);
                
            }
            return;
        }
        if(t>=cnd[ind]){
            arr.push_back(cnd[ind]);
            f(ind,t-cnd[ind],cnd,n);
            arr.pop_back();
        }

        f(ind+1,t,cnd,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(0,target,candidates,candidates.size());
        return ans;
    }
};