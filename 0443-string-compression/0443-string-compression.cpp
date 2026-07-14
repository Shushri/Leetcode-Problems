class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        chars.push_back(' ');
        if(n==1){
            return 1;
        }
        int pos=0;
        int i=1;
        int c=1;
        while(i<=n){
            c=1;
            while(i<=n && chars[i]==chars[i-1]){
                c++;
                i++;
            }
            if(c==1){
                chars[pos]=chars[i-1];
                pos++;
            }
            else{
                string cc=to_string(c);
                int cnt=cc.size();
                chars[pos++]=chars[i-1];
                for(int k=0;k<cnt;k++){
                    chars[pos++]=cc[k];
                }
            }
            i++;

        }

        chars.resize(pos);
        return pos;
    }
};