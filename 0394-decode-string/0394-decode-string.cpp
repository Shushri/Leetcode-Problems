class Solution {
public:
    string decodeString(string s) {
        stack<int> cnt;
        stack<string> st;
        string curr="";
        int num=0;
        for(auto ch:s){
            if(ch>='0' && ch<='9'){
                num=num*10+(ch-'0');
            }
            else if(ch=='['){
                st.push(curr);
                curr="";
                cnt.push(num);
                num=0;
            }
            else if(ch==']'){
                int n=cnt.top();
                cnt.pop();
                string p="";
                for(int i=0;i<n;i++){
                    p+=curr;
                }
                p=st.top()+p;
                curr=p;
                st.pop();
            }
            else{
                curr+=ch;
            }
        }

        return curr;

    }
};

//cnt=3
//st=""
//curr=a
//cnt=3 2
//st="" "a"
//curr=ac
//curr=acc
//cnt=3
//st=""
//curr=
