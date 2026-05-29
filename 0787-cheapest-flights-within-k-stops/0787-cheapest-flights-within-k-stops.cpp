class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> arr(n);//{{{1,2},{3,4}},{}}
        for(int i=0;i<flights.size();i++){
            arr[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dis(n,INT_MAX);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; //{k,{node,price}}
        pq.push({0,{src,0}});
        dis[src]=0;
        while(!pq.empty()){
            int pr=pq.top().second.second;
            int nd=pq.top().second.first;
            int c=pq.top().first;
            pq.pop();
            if(c>k){
                continue;
            }
            for(auto ele:arr[nd]){
                int dest=ele.first;
                int pp=ele.second;
                if(dis[dest]>pp+pr){
                    dis[dest]=pp+pr;
                    pq.push({c+1,{dest,pp+pr}});
                }
            }
        }
        if(dis[dst]==INT_MAX){
            return -1;
        }
        return dis[dst];

    }
};