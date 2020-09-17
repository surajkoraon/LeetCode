class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        int a=1;
        for(char s:instructions)
        {
            if(s=='G')
            {
                if(a&1)
                    y++;
                else if(a&2)
                    x--;
                else if(a&4)
                    y--;
                else if(a&8)
                    x++;
            }
            else if(s=='L')
            {
                a=a<<1;
                if(a>8)
                    a=1;
            }
            else if(s=='R')
            {
                a=a>>1;
                if(a==0)
                    a=8;
            }  
        }
        if((x==0 && y==0) || a!=1)
            return true;
        return false;
    }
};
