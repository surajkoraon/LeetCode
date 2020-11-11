class Solution {
public:
    int length(vector<int>& a,vector<int>& b)
    {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    bool helper(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        int a=length(p1,p2);
        int b=length(p1,p3);
        int c=length(p1,p4);
        if(a==0 || b==0 || c==0)
            return false;
        return ((a+b==c || a+c==b || b+c==a) && (a==b || b==c || a==c));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return helper(p1,p2,p3,p4)&&helper(p2,p1,p3,p4)&&helper(p3,p2,p1,p4);
    }
};
