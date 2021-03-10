class Solution {
public:
    map<int,string> m;
    string intToRoman(int num) {
        m[1]="I";
        m[5]="V";
        m[10]="X";
        m[50]="L";
        m[100]="C";
        m[500]="D";
        m[1000]="M";
        m[4]="IV";
        m[40]="XL";
        m[400]="CD";
        m[9]="IX";
        m[90]="XC";
        m[900]="CM";
        string roman;
        int index=0;
        auto it=--m.end();
        while(num>0)
        {
            while((it->first)>num)
            {
                it--;
            }
            roman+=(it)->second;
            num-=(it)->first;
        }
        return roman;
    }
};
