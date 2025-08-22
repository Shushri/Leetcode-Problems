class Solution {
public:
    string intToRoman(int n) {
        unordered_map <int,string> mpp; 
        mpp[1]="I";
        mpp[2]="II";
        mpp[3]="III";
        mpp[4]="IV";
        mpp[5]="V";
        mpp[6]="VI";
        mpp[7]="VII";
        mpp[8]="VIII";
        mpp[9]="IX";
        mpp[10]="X";
        mpp[20]="XX";
        mpp[30]="XXX";
        mpp[40]="XL";
        mpp[50]="L";
        mpp[60]="LX";
        mpp[70]="LXX";
        mpp[80]="LXXX";
        mpp[90]="XC";
        mpp[100]="C";
        mpp[200]="CC";
        mpp[300]="CCC";
        mpp[400]="CD";
        mpp[500]="D";
        mpp[600]="DC";
        mpp[700]="DCC";
        mpp[800]="DCCC";
        mpp[900]="CM";
        mpp[1000]="M";
        mpp[2000]="MM";
        mpp[3000]="MMM";

        string ans="";
        int i=1;
        while(n){
            int a=n%10;
            int b=a*i;
            ans=mpp[b]+ans;
            n=n/10;
            i*=10;
        }
        return ans;
    }
};