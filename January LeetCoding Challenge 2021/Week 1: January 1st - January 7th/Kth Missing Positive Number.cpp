class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count=arr[0]-1;
        if(count>=k)
            return k;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]>1)
            {
                count+=arr[i]-arr[i-1]-1;
                if(count>=k)
                    return arr[i]-(count-k)-1;
            }
        }
        return arr[n-1]+k-count;
    }
};
