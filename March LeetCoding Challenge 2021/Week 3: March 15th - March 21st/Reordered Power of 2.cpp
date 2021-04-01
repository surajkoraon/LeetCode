class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int num=1;
        string str=to_string(N);
        sort(str.begin(),str.end());
        while(num<1000000000)
        {
            string s=to_string(num);
            sort(s.begin(),s.end());
            if(s==str)
                return true;
            num=num<<1;
        }
        return false;
    }
};
