class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> vec(n);
        vector<int> indeg(n);
        for(int i=0;i<n;i++){
            indeg[i]=graph[i].size();
            for(auto ele:graph[i]){
                vec[ele].push_back(i);
            }
        } 
        queue <int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int > ans;
        while(!q.empty()){
            int nd=q.front();
            q.pop();
            ans.push_back(nd);
            for(auto p:vec[nd]){
                indeg[p]--;
                if(indeg[p]==0){
                    q.push(p);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};