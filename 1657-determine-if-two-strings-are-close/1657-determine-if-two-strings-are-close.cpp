class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int n1=w1.size();
        int n2=w2.size();
        if(n1!=n2){
            return false;
        }
        set<char> st1,st2;
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<n1;i++){
            st1.insert(w1[i]);
            st2.insert(w2[i]);
            mp1[w1[i]]++;
            mp2[w2[i]]++;
        }
        if(st1!=st2){
            return false;
        }
        multiset<char> nm1,nm2;
        for(auto ele:mp1){
            nm1.insert(ele.second);
        }
        for(auto ele:mp2){
            nm2.insert(ele.second);
        }
        if(nm1!=nm2){
            return false;
        }
        return true;

    }
};