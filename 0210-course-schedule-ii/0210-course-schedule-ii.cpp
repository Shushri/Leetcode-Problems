class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> sub(n);
        vector<int> indeg(n,0);
        for(int i=0;i<pre.size();i++){
            if(pre[i][1]==pre[i][0]){
                return {};
            }
            sub[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int nd=q.front();
            q.pop();
            ans.push_back(nd);
            for(auto ele:sub[nd]){
                indeg[ele]--;
                if(indeg[ele]==0){
                    q.push(ele);
                }
            }
        }
        if(ans.size()<n){
            return {};
        }
        return ans;
        

    }
};