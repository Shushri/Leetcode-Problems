class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> ans;
        priority_queue<P,vector<P>,greater<P>> pq;
        set<pair<int,int>> visited;
        int sm=nums1[0]+nums2[0];
        pq.push({sm,{0,0}});
        visited.insert({0,0});

        while(k>0 && !pq.empty()){
            auto ele=pq.top();
            pq.pop();
            int i=ele.second.first;
            int j=ele.second.second;

            ans.push_back({nums1[i],nums2[j]});

            if(i+1<n && visited.find({i+1,j})==visited.end()){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                visited.insert({i+1,j});
            }

            if(j+1<m && visited.find({i,j+1})==visited.end()){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                visited.insert({i,j+1});
            }

            k--;
        }
        return ans;
    }
};