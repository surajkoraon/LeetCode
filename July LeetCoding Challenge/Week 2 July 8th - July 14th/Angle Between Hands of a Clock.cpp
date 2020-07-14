class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=hour%12;
        double y=6*minutes;
        x=30*x+y/12;
        double sol;
        if(x>y)
            sol=x-y;
        else
            sol=y-x;
        if(360-sol>sol)
            return sol;
        return 360-sol;
    }
};
