class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n=tasks.size();
        unordered_map<char,int> mpp;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            mpp[tasks[i]]++;
        }
        for(auto &ele:mpp){
            pq.push(ele.second);
        }
        int ans=0;
        while(!pq.empty()){
            int c=p+1;
            int w=0;
            vector<int> temp;
            while(c-- && !pq.empty()){
                int ss=pq.top();
                w++;
                pq.pop();
                if(ss-1!=0) temp.push_back(ss-1);
            }

            for(auto ele:temp){
                pq.push(ele);
            }

            if(pq.empty()){
                ans+=w;
            }
            else{
                ans+=(p+1);
            }
            
        }
        return ans;


    }
};

// 3 3 
// 2 2 1 1 