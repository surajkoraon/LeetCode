class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        int i=0;
        while(1)
        {
            auto it=s.begin();
            advance(it,i);
            s.insert((*it)*2);
            s.insert((*it)*3);
            s.insert((*it)*5);
            i++;
            if(i>=n)
            {
                break;
            }
        }
        auto it=s.begin();
        advance(it,n-1);
        return *it;
    }
};
