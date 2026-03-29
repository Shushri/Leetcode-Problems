class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        set<char> a;
         set<char> b;
         set<char> c;
         set<char> d;

         for(int i=0;i<s1.size();i++){
            if(i&1){
                b.insert(s1[i]);
            }
            else{
                a.insert(s1[i]);
            }
         }
         for(int i=0;i<s2.size();i++){
            if(i&1){
                d.insert(s2[i]);
            }
            else{
                c.insert(s2[i]);
            }
         }
         if(b==d && a==c){
            return true;
         }
         return false;

    }
};