constexpr int N=5e4+1;
bitset<N> vis;
int q[N], front=0, back=0;
int nxt[N];
class Solution {
public:
    static int minJumps(vector<int>& arr) {
        const int n=arr.size();
        vis.reset();
        unordered_map<int, int> dict;
        dict.reserve(n);
        for(int i=0; i<n; i++){
            const int x=arr[i];
            auto it=dict.find(x);
            if(it==dict.end()) nxt[i]=-1;
            else nxt[i]=it->second;
            dict[x]=i;
        }
        front=back=0;
        q[back++]=0;
        
        for(int step=0; front<back; step++)
        {
            int s=back-front;
            while(s--)
            {
                int cur=q[front++];
                if (cur==n-1) return step;
                if(cur-1>=0 && !vis[cur-1]){
                    q[back++]=cur-1;
                    vis[cur-1]=1;
                }
                if(cur<=n && !vis[cur+1]){
                    q[back++]=cur+1;
                    vis[cur+1]=1;
                }
                const int x=arr[cur];
                for(int idx=dict[x]; idx!=-1; idx=nxt[idx]){
                    if (!vis[idx]){
                        q[back++]=idx;
                        vis[idx]=1;
                    }
                }
                dict[x]=-1;
            }
        }
        return -1;
    }
};