class Solution {
public:
    string shortestPalindrome(string s) {
        //using memcmp
        //memcmp(a,b,length);
        //return 0 if a==b
        //return <0 if a<b
        //return >0 if a>b
        int n=s.size();
        string rev=s;reverse(rev.begin(),rev.end());
        
        int ind=n;
        for(int i=0;i<n;i++){
            if(!memcmp(s.c_str(),rev.c_str()+i,n-i)){
                return rev.substr(0,i)+s;
            }
        }
        return s;

    }
};

//codewithmik
//abcd
//dcba
