class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> arr(n);
        for(int i=0;i<times.size();i++){
            arr[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        k=k-1;  //making it 0 based
        vector<int> tm(n,INT_MAX);
        tm[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//time,target node
        pq.push({0,k});
        while(!pq.empty()){
            int t2=pq.top().first;
            int nd=pq.top().second;
            pq.pop();
            for(auto p:arr[nd]){
                int t3=p.second;
                int nd2=p.first;
                if(t2+t3<tm[nd2]){
                    tm[nd2]=t2+t3;
                    pq.push({t2+t3,nd2});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,tm[i]);
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};