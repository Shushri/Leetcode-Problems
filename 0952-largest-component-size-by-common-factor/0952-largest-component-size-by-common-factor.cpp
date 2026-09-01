class DisJointSet{
    public:
        vector<int> parent;
        vector<int> size;
        DisJointSet(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findpar(int u){
            if(parent[u]==u) return u;
            return parent[u] = findpar(parent[u]);
        }
        void unionBySize(int u, int v){
            int upu=findpar(u);
            int upv=findpar(v);
            if(upu==upv) return ;
            if(size[upu]>size[upv]){
                parent[upv]=upu;
                size[upu]+=size[upv];
            }
            
            else{
                parent[upu]=upv;
                size[upv]+=size[upu];
            }
        }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        DisJointSet D(n+1);
        for(auto ele:nums){
            for(int i=2;i*i<=ele;i++){
                if(ele%i==0){
                    D.unionBySize(ele,i);
                    D.unionBySize(ele,ele/i);
                }
            }
        }
        
        unordered_map<int,int> mpp;
        for(auto ele:nums){
            int par=D.findpar(ele);
            mpp[par]++;

        }
        int ans=0;
        for(auto ele:mpp){
            ans=max(ans,ele.second);
        }
        return ans;
    }
};