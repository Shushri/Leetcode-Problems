class Solution {
public:
    void f(int ind,int t,vector<int>& cand, vector<vector<int>> &ans,vector<int> &arr){
        if(ind==cand.size()){
            if(t==0){
                ans.push_back(arr);
                
            }
            return;
        }
            
        if(t>0 && cand[ind]<=t ){
            arr.push_back(cand[ind]);
            f(ind,t-cand[ind],cand,ans,arr);
            arr.pop_back();
        }
        f(ind+1,t,cand,ans,arr);

    }
    vector<vector<int>> combinationSum(vector<int>& cand, int t) {
        vector<vector<int>> ans;
        vector<int> arr;

        f(0,t,cand,ans,arr);
        return ans;
    }
};