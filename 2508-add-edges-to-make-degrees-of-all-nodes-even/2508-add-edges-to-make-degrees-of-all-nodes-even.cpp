class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n+1,0);
        set<vector<int>> st;

        int m=edges.size();
        for(int i=0;i<m;i++){
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
            st.insert(edges[i]);
            st.insert({edges[i][1],edges[i][0]});
        }
        vector<int> odd;
        for(int i=0;i<=n;i++){
            if(deg[i]%2==1){
                odd.push_back(i);
            }
        }
        if(odd.size()==0){
            return true;
        }
        if(odd.size()!=2 && odd.size()!=4){
            return false;
        }
        if(odd.size()==2){
            int a=odd[0];
            int b=odd[1];
            if(st.count({a,b})==0){
                return true;
            }
            for(int i=1;i<=n;i++){
                if(i!=a && i!=b){
                    if(st.count({a,i})==0 && st.count({b,i})==0){
                        return true;
                    }
                }
            }
           return false;
        }
        if(odd.size()==4){
            int a=odd[0];
            int b=odd[1];
            int c=odd[2];
            int d=odd[3];
            
            
            if(!st.count({a,b}) && !st.count({c,d})){
                return true;
            }
            if(!st.count({a,c}) && !st.count({d,b})){
                return true;
            }
            if(!st.count({a,d}) && !st.count({c,b})){
                return true;
            }
            return false;
        }
        return false;


    }
};
//find out the degrees of al nodes
//see the nodes having odd degree
//if more than 4 nodes have odd degree... return false
//if odd no. of nodes have odd deg ... false
//then for these 2 and 4 nodes check all pairs if they dont already exist.
//and 4 me bhi bas 1 ke liye saare check kro if its pair doesnt already exist... check for left 2...
//if there are 2 and they are connected then we can have another node that is even and is not conn to a and b we can conn both and and b to c
//4 ke case me aisa kr nhi skte... because 2 se zyada edges add nhi krni