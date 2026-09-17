class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n=graph.size();
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                vector<int> arr=q.front();
                q.pop();
                int x=arr.back();
                int f=0;
                for(auto ele:graph[x]){
                    f=1;
                    vector<int> temp=arr;
                    arr.push_back(ele);
                    if(ele==n-1){
                        ans.push_back(arr);
                    }
                    else q.push(arr);
                    arr=temp;
                }
                if(f==0 && arr.back()==n-1){
                    ans.push_back(arr);
                }

            }
        }
        return ans;
    }
};