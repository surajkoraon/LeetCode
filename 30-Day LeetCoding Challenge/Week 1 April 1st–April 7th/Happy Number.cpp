class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(1)
        {
            n = digit(n);
            // cout<<n<<endl;
            if(n==1)
            {
                return 1;
            }
            else if(s.find(n)!=s.end())
            {
                return 0;
            }
            else
            {
                s.insert(n);
            }
        }
    }
    int digit(int n)
    {
        int result=0;
        while(n>0)
        {
            result += (n%10)*(n%10);
            n/=10;
        }
        return result;
    }
};