class Solution {
public:
    int reverse(int x) {
        string s;
        s=to_string(x);
        std::reverse(s.begin(),s.end());
        if(x<0){
            s.erase(s.begin()+s.size()-1,s.end());
            
        }
        long long n=stoll(s);
        if(x<0){
            n=n*(-1);
        }
        if (n > INT_MAX || n < INT_MIN) return 0;
        return (int)n;
    }
};