class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        unordered_map<int,int> mpp2;
        for(auto ele:mpp){
            if(mpp2[ele.second]>0){
                return false;
            }
            mpp2[ele.second]++;
        }
        return true;

    }
};