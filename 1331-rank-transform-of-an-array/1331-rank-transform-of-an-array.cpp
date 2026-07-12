class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;
        vector<vector<int>> vec(arr.size(),vector<int>(2));
        for(int i=0;i<arr.size();i++){
            vec[i][0]=arr[i];
            vec[i][1]=i;

        }
        sort(vec.begin(),vec.end());
        int r=1;
        for(int i=0;i<arr.size()-1;i++){
            arr[vec[i][1]]=r;
            if(vec[i+1][0]>vec[i][0]){
                r++;
            }
        }
        arr[vec[arr.size()-1][1]]=r;
        return arr;

    }
};