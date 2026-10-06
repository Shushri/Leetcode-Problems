class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& w, vector<vector<int>>& f, int id, int lev) {
        int n=w.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(id);
        vis[id]=1;
        for(int i=0;i<lev;i++){
            int x=q.size();
            while(x--){
                int tp=q.front();
                q.pop();
                for(auto ele:f[tp]){
                    if(!vis[ele]) {
                        vis[ele]=1;
                        q.push(ele);
                }}
            }
        }
        unordered_map<string,int> mpp;
        while(!q.empty()){
            int s=q.front();
            q.pop();
            for(auto c:w[s]){
                mpp[c]++;
            }
        }
        vector<pair<string,int>> vcc(mpp.begin(),mpp.end());
        sort(vcc.begin(),vcc.end(),[](auto &a,auto &b){
            if(a.second==b.second) return a.first<b.first ;
            return a.second<b.second;
        });
        vector<string> ans;
        for(auto ele:vcc){
            ans.push_back(ele.first);
        }
        return ans;


    }
};