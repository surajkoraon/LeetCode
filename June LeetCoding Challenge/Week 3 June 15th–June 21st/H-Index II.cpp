class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0)
            return 0;
        int left=0;
        int right=citations.size()-1;
        int n=right+1;
        int mid;
        int sol=INT_MIN;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(citations[mid]==n-mid)
                return citations[mid];
            if(citations[mid]>n-mid)
            {
                sol=max(sol,n-mid);
                right=mid-1; 
            }
            else
            {
                sol=max(sol,citations[mid]);
                left=mid+1;
            }
        }
        return sol;
    }
};
