class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        //kanh's algo (bfs on toopo sort)
        vector<int> indeg(n);
        vector<vector<int>> sub(n);
        for(int i=0;i<pre.size();i++){
            if(pre[i][0]==pre[i][1]){
                return false;
            }
            sub[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        
        while(!q.empty()){
            int nd=q.front();
            q.pop();
            ans.push_back(nd);
            for(auto p:sub[nd]){
                indeg[p]--;
                if(indeg[p]==0){
                    q.push(p);
                }
            }
        }
        if(ans.size()<n){
            return false;
        }
        return true;
    }
};