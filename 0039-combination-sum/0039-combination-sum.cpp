class Solution {
public:
    void fxn(int ind,int n,vector<int> &arr,int t,vector<int>& cand, vector<vector<int>> &ans){
        if(ind==n){
            if(t==0){
                ans.push_back(arr);
            }
            return;
        } 
        if(cand[ind]<=t){
            arr.push_back(cand[ind]);
            fxn(ind,n,arr,t-cand[ind],cand,ans);
            arr.pop_back();
        }
        fxn(ind+1,n,arr,t,cand,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        vector<vector<int>> ans;
        vector<int> arr;
        fxn(0,cand.size(),arr,t,cand,ans);
        return ans;
        
    }
};