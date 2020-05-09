class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        int l=0;
        int r=num/2;
        double mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(mid==(double)num/mid)
                return true;
            if(mid>(double)num/mid)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
};
