class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;

    void f(int ind,int t,vector<int> &cnd,int n){
        
            if(t==0){
                ans.push_back(arr);
                return;
            }
        

        for(int i=ind ; i<n;i++){
            if(cnd[i]>t) break;
            if(i>ind && cnd[i]==cnd[i-1] ) continue;

            arr.push_back(cnd[i]);
            f(i+1,t-cnd[i],cnd,n);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(0,target,candidates,candidates.size());
        
        return ans;
    }
};