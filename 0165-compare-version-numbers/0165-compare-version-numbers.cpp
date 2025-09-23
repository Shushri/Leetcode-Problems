class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<long long> v1;
        vector<long long> v2;
        string s="";
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'){
                v1.push_back(stoi(s));
                s="";
            }
            else{
                s+=version1[i];
            }
        }
        v1.push_back(stoi(s));
        s="";
        for(int i=0;i<version2.size();i++){
            if(version2[i]=='.'){
                v2.push_back(stoi(s));
                s="";
            }
            else{
                s+=version2[i];
            }
        }
        v2.push_back(stoi(s));
        if(v1.size()>v2.size()){
            
            for(int i=v2.size();i<v1.size();i++){
                v2.push_back(0);
            }
        }
        else{
            for(int i=v1.size();i<v2.size();i++){
                v1.push_back(0);
            }
        }
        // for(auto ele:v1){
        //     cout<<ele<<"  ";
        // }
        // cout<<endl;
        // for(auto ele:v2){
        //     cout<<ele<<"  ";
        // }
        // cout<<endl;
        int n=v1.size();

        for(int i=0;i<n;i++){
            if(v1[i]>v2[i]){
                return 1;
            }
            else if(v1[i]<v2[i]){
                return -1;
            }
            
        }
        return 0;
    }
};