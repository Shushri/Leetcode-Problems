class Solution {
public:
    void fxn(int ind,vector<int> &temp,int n,vector<vector<int>> &ans,vector<int>& cand){
            
        ans.push_back(temp);
            
        for(int i=ind;i<n;i++){
            
            if(i>ind && cand[i]==cand[i-1]) continue;
            temp.push_back(cand[i]);
            fxn(i+1,temp,n,ans,cand);
            temp.pop_back();
        }   
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& cand) {
        sort(cand.begin(),cand.end());
        int n=cand.size();
        vector<vector<int>> ans;
        vector<int> temp;
        
        fxn(0,temp,n,ans,cand);
        
        return ans;   
    }
};