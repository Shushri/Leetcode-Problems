class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        map<int,pair<pair<int,int>,char>> mpp;
        int n=pos.size();
        for(int i=0;i<n;i++){
            mpp[pos[i]]={{h[i],i},dir[i]};
        }
        stack<pair<pair<int,int>,char>> st;
        for(auto ele:mpp){
            int ind=ele.second.first.second;
            int hs=ele.second.first.first;
            char d=ele.second.second;
            
            int f=0;
            while(!st.empty() && st.top().second=='R' && d=='L'){
                if(hs==st.top().first.second){
                    st.pop();
                    f=1;
                    break;
                    
                    
                }
                else if(st.top().first.second<hs){
                    st.pop();
                    hs=hs-1;
                    
                }
                else if(st.top().first.second>hs){
                    pair<pair<int,int>,char> tp=st.top();
                    int pp=tp.first.second;
                    int ip=tp.first.first;
                    char cp=tp.second;
                    pp-=1;
                    st.pop();
                    st.push({{ip,pp},cp});
                    f=1;
                    break;

                }
            }
            if(f==0) { st.push({{ind,hs},d}) ;}

        }
        vector<pair<int,int>> ans;
        while(!st.empty()){
            ans.push_back({st.top().first.first,st.top().first.second});
            st.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int> anss;
        for(int i=0;i<ans.size();i++){
            anss.push_back(ans[i].second);
        }
        return anss;
    }
};