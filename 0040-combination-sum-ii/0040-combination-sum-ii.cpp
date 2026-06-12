class Solution {
public:
    void fxn(int ind,int t,vector<int> &temp,int n,vector<vector<int>> &ans,vector<int>& cand){
        
            if(t==0){
                ans.push_back(temp);
                return ;
            }
        for(int i=ind;i<n;i++){
            if(cand[i]>t) break;
            if(i>ind && cand[i]==cand[i-1]) continue;
            temp.push_back(cand[i]);
            fxn(i+1,t-cand[i],temp,n,ans,cand);
            temp.pop_back();
        }   
        
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int t) {
        sort(cand.begin(),cand.end());
        int n=cand.size();
        vector<vector<int>> ans;
        vector<int> temp;
        
        fxn(0,t,temp,n,ans,cand);
        
        return ans;
    }
};