class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
            if(find(wl.begin(),wl.end(),ew)==wl.end()){
                return 0;
            }    
            
            unordered_set<string> st(wl.begin(),wl.end());
            queue<pair<int,string>> q;
            q.push({1,bw});
            
            st.erase(bw);
            while(!q.empty()){
                int sz=q.size();
                for(int i=0;i<sz;i++){
                    int lev=q.front().first;
                    string temp=q.front().second;
                    q.pop();
                    if(temp==ew){
                        return lev;
                    }
                    for(int j=0;j<temp.size();j++){
                        char orig=temp[j];
                        for(char c='a';c<='z';c++){
                            
                            temp[j]=c;
                            if(st.find(temp)!=st.end()){
                                
                                st.erase(temp);
                                q.push({lev+1,temp});
                            }
                        }
                        temp[j]=orig;
                    }

                }
            }
            return 0;

    }
};