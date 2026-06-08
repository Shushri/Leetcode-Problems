class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n=nums.size();
        vector<int> pre;
        vector<int> pst;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]<p){
                pre.push_back(nums[i]);

            }
            else if(nums[i]>p){
                pst.push_back(nums[i]);
            }
            else{
                c++;
            }
        }
        vector<int> ans;
        for(int i=0;i<pre.size();i++){
            ans.push_back(pre[i]);
        }
        for(int i=0;i<c;i++){
            ans.push_back(p);
        }
        for(int i=0;i<pst.size();i++){
            ans.push_back(pst[i]);
        }
        return ans;
    }
};