class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int n=s.size();
        int p=0;
        for(int i=0;i<n;i++){
            if(s[i]=='6'){
                p=i+1;
                break;
            }
        }
        if(p==0){
            return num;
        }
        num=num-6*(int)pow(10.0,(double)(n-p))+9*(int)pow(10.0,(double)(n-p));
        return num;
    }
};