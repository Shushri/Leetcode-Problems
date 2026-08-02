class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n1;i++){
            arr.push_back({nums2[i],nums1[i]});
        }
        sort(arr.rbegin(),arr.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sm=0;
        long long ans=0;
        for(auto ele:arr){
            int a=ele.first;
            int b=ele.second;
            sm+=b;
            pq.push(b);
            
            if(pq.size()>k){
                sm-=pq.top();
                pq.pop();

            }
            if(pq.size()==k){
                ans=max(ans,sm*a);
            }
        }
        return ans;
    }
};