class Solution {
public:
    double _radius,x,y;
    double helper()
    {
        return (double)rand()/RAND_MAX;
    }
    Solution(double radius, double x_center, double y_center) {
        _radius=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() {
        double theta = 2 * double(22)/(double)7 * helper();
        double r = sqrt(helper());
        return {x+_radius*r*cos(theta),y+_radius*r*sin(theta)};
    }
};
