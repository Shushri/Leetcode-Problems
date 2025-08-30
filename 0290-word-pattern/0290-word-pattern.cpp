class Solution {
public:
    bool wordPattern(string p, string s) {
        vector <string> arr;
        string sn="";
        for (int i=0;i<s.size();i++){
            if(s[i]==' '){
                arr.push_back(sn);
                sn="";
                
            }
            else{
                sn+=s[i];
            }
            

        }
        arr.push_back(sn);
        if(arr.size()!=p.size()) return false;
        
        
        unordered_map<char,string> mpp;
        unordered_map<string,char> revmpp;
        for (int i=0;i<p.size();i++){
            
            if(!mpp.count(p[i]) && !revmpp.count(arr[i]) ){
                mpp[p[i]]=arr[i];
                revmpp[arr[i]]=p[i];
            }
            else{
                if(mpp[p[i]]!=arr[i] || revmpp[arr[i]]!=p[i]){
                    return false;
                }
                
            }
        }
        return true;
    }
};