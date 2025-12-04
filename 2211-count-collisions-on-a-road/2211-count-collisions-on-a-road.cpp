class Solution {
public:
    int countCollisions(string d) {
        int i=0;
        int c=0;
        int n=d.size();
        while(i<n && d[i]=='L' ){
            i++;
        }
        int j=d.size()-1;
        while(j>=0 &&  d[j]=='R'){
            j--;
        }
        if((int)j<=(int)i){
            return 0;
        }
        int p=0;
        char lst=i==0?d[0]:d[i];
        for(int k=i+1;k<=j;k++){
            if(lst=='R'){
                if(d[k]=='L'){
                    c+=2;
                    lst='S';
                }
                if(d[k]=='S'){
                    c+=1;
                    lst='S';
                }
                if(d[k]=='R'){
                    
                    lst='R';
                    p++;
                }

            }
            else if(lst=='S'){
                if(d[k]=='L'){
                    c+=1;
                    lst='S';
                }
                if(d[k]=='R'){
                    
                    lst='R';
                }

                
            }
        }
        return c+p;
    }
};