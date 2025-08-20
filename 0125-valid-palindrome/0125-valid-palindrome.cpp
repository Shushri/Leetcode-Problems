class Solution {
public:
    bool isPalindrome(string st) {
        string s="";
        for (int i=0;i<st.size();i++){

            if((st[i]>='a' && st[i]<='z') || (st[i]>='A' && st[i]<='Z') || (st[i]>='0' && st[i]<='9')){
                s+=tolower(st[i]);
                
            }
        }
        string ts=s;
        cout<<s<<" "<<ts<<endl;
        reverse(s.begin(),s.end());
        cout<<s<<" "<<ts<<endl;
        return s==ts;
    }
};