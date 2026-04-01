class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        map<int ,int> mpp;
        int n=hand.size();
        for(int i=0;i<n;i++){
            mpp[hand[i]]++;

        }

        while(!mpp.empty()){
            auto it = mpp.begin();
            int f=it->first;
            int c=g-1;
            mpp[f]--;
            if(mpp[f]==0){
                mpp.erase(f);
            }
            while(c--){
                if(mpp.count(f+1)>0){
                    f=f+1;
                    mpp[f]--;
                    if(mpp[f]==0){
                        mpp.erase(f);
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;

    }
};