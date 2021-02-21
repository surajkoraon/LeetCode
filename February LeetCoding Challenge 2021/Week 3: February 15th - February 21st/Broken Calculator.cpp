class Solution {
public:
    int brokenCalc(int X, int Y) {
        int steps=0;
        while(X<Y)
        {
            if(Y&1)
                Y++;
            else
                Y/=2;
            steps++;
        }
        return steps+X-Y;
    }
};