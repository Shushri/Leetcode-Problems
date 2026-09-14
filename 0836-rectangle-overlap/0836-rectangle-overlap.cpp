class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a1=rec1[0];
        int a2=rec1[1];
        int b1=rec1[2];
        int b2=rec1[3];
        int c1=rec2[0];
        int c2=rec2[1];
        int d1=rec2[2];
        int d2=rec2[3];
        if(a1>=c1 && a1<d1 ){
            if(a2>=c2 && a2<d2)
                return true;
            if(a2<c2 && b2>c2){
                return true;
            }
        }
        if(b1>c1 && b1<=d1 ){
            if (b2>c2 && b2<=d2)
                return true;
            if(b2>d2 && a2<d2){
                return true;
            }
        }
        if(c1>=a1 && c1<b1 ){
            if(c2>=a2 && c2<b2)
                return true;
            if(c2<a2 && d2>a2){
                return true;
            }
        }
        if(b1>c1 && b1<=d1 ){
            if (b2>c2 && b2<=d2)
                return true;
            if(b2>d2 && a2<d2){
                return true;
            }
        }
        
        return false;
    }
};