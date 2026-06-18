class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans={1};
        while(ans.size()<n){
            vector<int> temp;
            for(auto ele:ans){
                if(2*ele-1<=n){
                    temp.push_back(2*ele-1);
                }
            }
            for(auto ele:ans){
                if(2*ele<=n){
                    temp.push_back(2*ele);
                }
            }
            ans=temp;
        }
        return ans;
    }
};

//1 2 3 4 5 
//1
//1 
//1 2
//1 3
//1 3 2 4
//1 5 3 
//1 5 3 2 4
