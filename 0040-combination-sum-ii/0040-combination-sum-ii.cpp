class Solution {
public:
    void f(int ind,int t,vector<int>& cand,vector<vector<int>> &ans,vector<int> &arr){
        if(t==0){
                ans.push_back(arr);
                return;        
        }
        for(int i=ind;i<cand.size();i++){
            if(cand[i]>t) break;
            if(i>ind && cand[i]==cand[i-1]){
                continue;
            }
            
            
                arr.push_back(cand[i]);
                f(i+1,t-cand[i],cand,ans,arr);
                arr.pop_back();
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int t) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(cand.begin(),cand.end());
        f(0,t,cand,ans,arr);
        return ans;
    }
};

//1 1 2 2 3 4 6 6 7