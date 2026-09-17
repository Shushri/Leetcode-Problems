class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int t) {
        int n=arr.size();
        vector<pair<int,int>> vec;
        int i=0;int j=0;
        int sm=0;
        while(j<n){
            sm+=arr[j];
            if(sm==t){
                vec.push_back({i,j});
                sm-=arr[i];
                i++;
                j++;
                
            }
            else if(sm>t){
                if(i==j){
                    sm-=arr[j];
                    i++;
                    j++;
                    
                }
                else{
                    sm-=arr[i];
                    i++;
                    sm-=arr[j];
                }
            }
            else{
                j++;
            }
        }
        // for(auto ele:vec){
        //     cout<<ele.first<<" ";
        //     cout<<ele.second<<endl;
        // }
        if(vec.size()<2 ){
            return -1;
        }
        
        int m = vec.size();
        int ans = INT_MAX;

        int minLen = INT_MAX;
        int p = 0;

        for(int q = 0; q < m; q++) {

            // Add all intervals that end before vec[q] starts
            while(p < q && vec[p].second < vec[q].first) {
                int len = vec[p].second - vec[p].first + 1;
                minLen = min(minLen, len);
                p++;
            }

            if(minLen != INT_MAX) {
                int currLen = vec[q].second - vec[q].first + 1;
                ans = min(ans, minLen + currLen);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;

        
    }
};
//use 2 pointer
//if sm==t add initial and final pointer to vector of pairs 
//find 2 non over intervals of shortest length from that arr