class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int sol=INT_MIN;
        int dist=-1;
        int n=seats.size();
        int i=0;
        for(i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                if(dist<0)
                    sol=max(sol,i-dist-1);
                else
                    sol=max(sol,(i-dist)/2);
                dist=i;
            }
        }
        sol=max(sol,i-dist-1);
        return sol;
    }
};
